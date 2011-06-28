//  
//	FILE NAME:	$RCSfile: DataProxyServiceSystest.cpp,v $
//  
//	DESCRIPTION:	
//  
//	REVISION:		$Revision$
//  
//	COPYRIGHT:	(c) 2007 Advertising.com All Rights Reserved.
//  
//	LAST UPDATED:	$Date$
//	UPDATED BY:	$Author$

#include "DataProxyServiceSystest.hpp"
#include "TempDirectory.hpp"
#include "FileUtilities.hpp"
#include "NetworkUtilities.hpp"
#include "ShellExecutor.hpp"
#include "RESTClient.hpp"
#include <fstream>
#include <vector>
#include <boost/regex.hpp>
#include <boost/lexical_cast.hpp>

CPPUNIT_TEST_SUITE_REGISTRATION( DataProxyServiceSystest );

DataProxyServiceSystest::DataProxyServiceSystest( void )
:   m_pTempDir(NULL)
{
}

DataProxyServiceSystest::~DataProxyServiceSystest( void )
{
}

void DataProxyServiceSystest::setUp( void )
{
	m_pTempDir.reset( new TempDirectory() );
}

void DataProxyServiceSystest::tearDown( void )
{
	m_pTempDir.reset( NULL );
}

void DataProxyServiceSystest::testHappyPath( void )
{
	std::string nodeDir( m_pTempDir->GetDirectoryName() + "/nodeDir" );
	CPPUNIT_ASSERT_NO_THROW( FileUtilities::CreateDirectory( nodeDir ) );

	std::string dplConfigFileSpec = m_pTempDir->GetDirectoryName() + "/dplConfig.xml";
	std::ofstream file( dplConfigFileSpec.c_str() );
	file << "<DplConfig>" << std::endl
		 << "  <DataNode name=\"/my/path\" type=\"local\" location=\"" << nodeDir << "\" />" << std::endl
		 << "</DplConfig>" << std::endl;
	file.close();

	uint port = NetworkUtilities::FindEmptyPort();

	std::stringstream cmd;
	cmd << "./dplService "
		<< " --dpl_config " << dplConfigFileSpec
		<< " --port " << port
		<< " --instance_id systemtest_instance"
		<< " --num_threads 4";
	
	ShellExecutor exe( cmd.str() );
	std::stringstream out;
	std::stringstream err;

	exe.RunInBackground( out, err );

	::usleep( 50000 );

	std::stringstream endpoint;
	endpoint << "http://localhost:" << port << "/my/path/?query1=value1&query2=value2";

	// POST data to the service
	std::stringstream data;
	data << "This is some data that will eventually be returned via GET";
	RESTParameters params;
	params.SetCompression( IDENTITY );
	RESTClient client;
	CPPUNIT_ASSERT_NO_THROW( client.Post( endpoint.str(), data ) );

	// now GET it back
	std::stringstream results;
	CPPUNIT_ASSERT_NO_THROW( client.Get( endpoint.str(), results, params ) );
	CPPUNIT_ASSERT_EQUAL( data.str(), results.str() );

	results.str("");
	params.SetCompression( DEFLATE );
	CPPUNIT_ASSERT_NO_THROW( client.Get( endpoint.str(), results, params ) );
	CPPUNIT_ASSERT_EQUAL( data.str(), results.str() );

	results.str("");
	params.SetCompression( GZIP );
	CPPUNIT_ASSERT_NO_THROW( client.Get( endpoint.str(), results, params ) );
	CPPUNIT_ASSERT_EQUAL( data.str(), results.str() );
}
