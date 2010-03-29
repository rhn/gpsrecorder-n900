//***************************************************************************
//
// Author     : Jean-Charles Lefebvre
// Created On : 2010-03-14 18:43:32
//
// $Id$
//
//***************************************************************************

#ifndef __GPSRECORD_UTIL_H__
#define __GPSRECORD_UTIL_H__


//---------------------------------------------------------------------------
// Util
//---------------------------------------------------------------------------
class Util
{
public :

  // file system
  static bool               fileExists      (const char* pszFile);
  static bool               fileIsDir       (const char* pszFile);
  static QFile::Permissions filePermissions (const char* pszFile);

  // time
  static const char* timeString (bool bForFilename=false, time_t nTime=0);
};


#endif // #ifndef __GPSRECORD_UTIL_H__
