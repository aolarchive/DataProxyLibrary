// FILE NAME:       $RCSfile: DatabaseProxyTest.hpp,v $
//
// REVISION:        $Revision$
//
// COPYRIGHT:       (c) 2006 Advertising.com All Rights Reserved.
//
// LAST UPDATED:    $Date$
// UPDATED BY:      $Author$

#ifndef _DATABASE_PROXY_TEST_HPP_
#define _DATABASE_PROXY_TEST_HPP_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include "DatabaseProxy.hpp"

class TempDirectory;

class DatabaseProxyTest : public CppUnit::TestFixture
{
private:
	CPPUNIT_TEST_SUITE( DatabaseProxyTest );
	CPPUNIT_TEST (testConstructorExceptionWithNoReadOrWriteNode);
	CPPUNIT_TEST (testConstructorExceptionIllegalXml);

	CPPUNIT_TEST (testOperationNotSupported);
	
	CPPUNIT_TEST (testLoadExceptionMissingVariableNameDefinition);
	CPPUNIT_TEST (testLoadExceptionWithBadConnection);
	CPPUNIT_TEST (testLoadExceptionEmptyVarName);

	CPPUNIT_TEST (testOracleLoad);
	CPPUNIT_TEST (testMySQLLoad);
	CPPUNIT_TEST (testLoadWithExtraVariableNameDefinitions);
	CPPUNIT_TEST (testLoadWithMultipleVariableNames);
	CPPUNIT_TEST (testLoadWithNoVariableNames);
	CPPUNIT_TEST (testLoadMaxStringParameter);
	CPPUNIT_TEST (testLoadSameVarNameReplacedTwice);
	CPPUNIT_TEST (testLoadCustomSeparators);

	CPPUNIT_TEST (testStoreException);

	CPPUNIT_TEST (testOracleStore);
	CPPUNIT_TEST (testMySqlStore);
	CPPUNIT_TEST (testMySqlStoreDynamicTables);
	CPPUNIT_TEST (testOracleStoreDynamicTables);
	CPPUNIT_TEST (testDynamicTableNameLength);
	CPPUNIT_TEST (testStoreParameterOnly);
	CPPUNIT_TEST (testStoreColumnParameterCollisionBehaviors);

	CPPUNIT_TEST_SUITE_END();

public:
	DatabaseProxyTest();
	virtual ~DatabaseProxyTest();

	void setUp();
	void tearDown();

	void testConstructorExceptionIllegalXml();
	void testConstructorExceptionWithNoReadOrWriteNode();

	void testOperationNotSupported();

	void testLoadExceptionMissingVariableNameDefinition();
	void testLoadExceptionWithBadConnection();
	void testLoadExceptionEmptyVarName();

	void testOracleLoad();
	void testMySQLLoad();
	void testLoadWithExtraVariableNameDefinitions();
	void testLoadWithMultipleVariableNames();
	void testLoadWithNoVariableNames();
	void testLoadMaxStringParameter();
	void testLoadSameVarNameReplacedTwice();
	void testLoadCustomSeparators();

	void testStoreException();

	void testOracleStore();
	void testMySqlStore();
	void testMySqlStoreDynamicTables();
	void testOracleStoreDynamicTables();
	void testDynamicTableNameLength();
	void testStoreParameterOnly();
	void testStoreColumnParameterCollisionBehaviors();

private:
	boost::shared_ptr<TempDirectory> m_pTempDir;
	boost::shared_ptr<Database> m_pOracleDB;
	boost::shared_ptr<Database> m_pMySQLDB;
	boost::shared_ptr<Database> m_pOracleObservationDB;
	boost::shared_ptr<Database> m_pMySQLObservationDB;
};

#endif //_DATABASE_PROXY_TEST_HPP_
