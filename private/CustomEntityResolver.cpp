//
// FILE NAME:       $RCSfile: CustomEntityResolver.cpp,v $
//
// REVISION:        $Revision$
//
// COPYRIGHT:       (c) 2006 Advertising.com All Rights Reserved.
//
// LAST UPDATED:    $Date$
// UPDATED BY:      $Author$

#include "CustomEntityResolver.hpp"
#include "XMLUtilities.hpp"
#include "MVLogger.hpp"
#include <xercesc/framework/LocalFileInputSource.hpp>

namespace
{
	const std::string HTTP_PROTO( "http://" );
}

CustomEntityResolver::CustomEntityResolver()
{
}

CustomEntityResolver::~CustomEntityResolver()
{
}

xercesc::InputSource* CustomEntityResolver::resolveEntity( const XMLCh* const i_PublicId, const XMLCh* const i_SystemId )
{
	std::string systemId( XMLUtilities::XMLChToString( i_SystemId ) );
	if( systemId.substr( 0, HTTP_PROTO.size() ) == HTTP_PROTO )
	{
		MVLOGGER( "root.lib.DataProxy.CustomEntityResolver.ResolveEntity.SkippingEntityResolution",
			"Entity resolution over HTTP is not currently supported. The following entity will not be resolved: '" << systemId << "'" );
		return NULL;
	}

	std::stringstream msg;
	msg << "Resolving entity with system id: " << systemId;
	if( i_PublicId != NULL )
	{
		msg << " with public id: " <<  XMLUtilities::XMLChToString( i_PublicId );
	}
	MVLOGGER( "root.lib.DataProxy.CustomEntityResolver.ResolveEntity.LocalFileInput", msg.str() );
	return new LocalFileInputSource( i_SystemId );
}
