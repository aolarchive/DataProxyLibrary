//  
//    FILE NAME:	$RCSfile: DataProxyService.hpp,v $
//  
//    DESCRIPTION:    
//  
//    REVISION:		$Revision$
//  
//    COPYRIGHT:	(c) 2007 Advertising.com All Rights Reserved.
//  
//    LAST UPDATED:	$Date$
//    UPDATED BY:	$Author$

#ifndef __DATA_PROXY_SERVICE_HPP__
#define __DATA_PROXY_SERVICE_HPP__

#include <string>

#ifdef MV_OPTIMIZE
#define MV_VIRTUAL
#else
#define MV_VIRTUAL virtual
#endif

#define DATA_PROXY_SERVICE_VERSION "Data Proxy Service v3.1.0"

const std::string SERVER( "Server" );
const std::string X_FORWARDED_FOR( "X-Forwarded-For" );

#endif //__DATA_PROXY_SERVICE_HPP__
