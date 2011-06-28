// FILE NAME:       $RCSfile: ProxyUtilitiesTest.hpp,v $
//
// REVISION:        $Revision$
//
// COPYRIGHT:       (c) 2006 Advertising.com All Rights Reserved.
//
// LAST UPDATED:    $Date$
// UPDATED BY:      $Author$

#ifndef _PROXY_UTILITIES_TEST_HPP_
#define _PROXY_UTILITIES_TEST_HPP_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <boost/scoped_ptr.hpp>

class TempDirectory;

class ProxyUtilitiesTest : public CppUnit::TestFixture
{
private:
	CPPUNIT_TEST_SUITE( ProxyUtilitiesTest );
	CPPUNIT_TEST( testToString );
	CPPUNIT_TEST( testGetMergeQuery_IllegalXml );
	CPPUNIT_TEST( testGetMergeQuery_InsertOnly );
	CPPUNIT_TEST( testGetMergeQuery_FullMerge_Oracle );
	CPPUNIT_TEST( testGetMergeQuery_FullMerge_MySql );
	CPPUNIT_TEST( testGetMergeQuery_NotMatch_Oracle );
	CPPUNIT_TEST( testGetMergeQuery_NotMatch_MySql );
	CPPUNIT_TEST( testGetMergeQuery_Match_Oracle );
	CPPUNIT_TEST( testGetMergeQuery_Match_MySql );
	CPPUNIT_TEST_SUITE_END();

public:
	ProxyUtilitiesTest();
	virtual ~ProxyUtilitiesTest();

	void setUp();
	void tearDown();

	void testToString();
	void testGetMergeQuery_IllegalXml();
	void testGetMergeQuery_InsertOnly();
	void testGetMergeQuery_FullMerge_Oracle();
	void testGetMergeQuery_FullMerge_MySql();
	void testGetMergeQuery_NotMatch_Oracle();
	void testGetMergeQuery_NotMatch_MySql();
	void testGetMergeQuery_Match_Oracle();
	void testGetMergeQuery_Match_MySql();

private:
	boost::scoped_ptr< TempDirectory > m_pTempDir;
};

#endif //_PROXY_UTILITIES_TEST_HPP_
