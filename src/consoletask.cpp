#include "consoletask.h"
#include "Exporter.h"
#include "ExporterSink.h"
#include <QDebug>

ConsoleTask::ConsoleTask(QObject *parent) : QObject(parent)
{

}

void ConsoleTask::run(void) {
    Exporter exporter;
    ExporterSinkTxt* pSinkTxt = 0;
    ExporterSinkCsv* pSinkCsv = 0;
    ExporterSinkGpx* pSinkGpx = 0;
    ExporterSinkKml* pSinkKml = 0;
    uint uiSuccessCount = 0;
    QStringList files = QCoreApplication::instance()->arguments().mid(1);
    // get data

    // create needed export sinks
/*    if (m_pChkTxt->checkState() != Qt::Unchecked)
      pSinkTxt = new ExporterSinkTxt(&exporter);
    if (m_pChkCsv->checkState() != Qt::Unchecked)
      pSinkCsv = new ExporterSinkCsv(&exporter);
    if (m_pChkGpx->checkState() != Qt::Unchecked)*/
      pSinkGpx = new ExporterSinkGpx(&exporter);
/*    if (m_pChkKml->checkState() != Qt::Unchecked)
      pSinkKml = new ExporterSinkKml(&exporter);*/

    // do export
    uiSuccessCount = exporter.exportFiles(files);

    // free export sinks
//    delete pSinkTxt;
  //  delete pSinkCsv;
    delete pSinkGpx;
    //delete pSinkKml;

    // inform user
    {
      if (uiSuccessCount != files.size()) {
        qDebug() << tr("%1 files exported successfully.").arg(uiSuccessCount);
        exit(1);
      }
    }
    qDebug("OK");
    exit(0);
}
