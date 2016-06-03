//***************************************************************************
//
// GPS Recorder
// A GPS data logger for the Maemo platform.
//
// Copyright (C) 2010 Jean-Charles Lefebvre <polyvertex@gmail.com>
//
// This software is provided 'as-is', without any express or implied
// warranty.  In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions :
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
// 2. Altered source versions must be plainly marked as such, and must not
//    be misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.
//
// Created: 2010-03-09 18:29:46
//
//***************************************************************************

#include "stable.h"
#include "version.h"
#include "consoletask.h"
#include <QDebug>

//---------------------------------------------------------------------------
// Local Variables
//---------------------------------------------------------------------------
static FILE*      hLogFile = 0;
static QByteArray strLogStart;


//---------------------------------------------------------------------------
// m a i n
//---------------------------------------------------------------------------
int main (int nArgc, char** ppszArgv)
{
  int nRes;

  QCoreApplication::setOrganizationName("jcl");
  //QCoreApplication::setOrganizationDomain("example.com");
  QCoreApplication::setApplicationName("gpsrecorder");
  QCoreApplication::setApplicationVersion(APP_VERSION_STR);

  qDebug("%s version %s compiled on " __DATE__ " at " __TIME__ ".\n",
    qPrintable(QCoreApplication::applicationName()),
    qPrintable(QCoreApplication::applicationVersion()));

  fflush(NULL);

  strLogStart = Util::timeString();

  // run
  {
    QCoreApplication app(nArgc, ppszArgv, 0);
    ConsoleTask task;
    QTimer::singleShot(0, &task, SLOT(run()));
    nRes = app.exec();
  }

  // close log file
  // at this point, App instance must be destroyed !
  qInstallMsgHandler(0);
  if (hLogFile)
  {
    fputs("\n", hLogFile);
    fclose(hLogFile);
  }

  return nRes;
}
