//
// FILE NAME:           $RCSfile: UTCTimeProviderTest.hpp,v $
//
// REVISION:            $Revision: 213033 $
//
// COPYRIGHT:           (c) 2005 Advertising.com All Rights Reserved.
//
// LAST UPDATED:        $Date: 2011-06-22 17:12:18 -0400 (Wed, 22 Jun 2011) $
//
// UPDATED BY:          $Author: robarson $
//
#ifndef _ATOMICS_JSON_TO_CSV_CONVERTER_TEST_HPP
#define _ATOMICS_JSON_TO_CSV_CONVERTER_TEST_HPP

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class AtomicsJSONToCSVTest : public CppUnit::TestFixture
{
private:
	CPPUNIT_TEST_SUITE( AtomicsJSONToCSVTest );
	CPPUNIT_TEST( testConvert );
	CPPUNIT_TEST( testConvertWithNoRecords );
	CPPUNIT_TEST( testConvertWithCommasInRecordsAndColumnNames );
	CPPUNIT_TEST_SUITE_END();

public:
	AtomicsJSONToCSVTest();
	virtual ~AtomicsJSONToCSVTest();

	void setUp(void);
	void tearDown(void);
	void testConvert();
	void testConvertWithNoRecords();
	void testConvertWithCommasInRecordsAndColumnNames();
	
};

#endif //_ATOMICS_JSON_TO_CSV_CONVERTER_TEST_HPP_