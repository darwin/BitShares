#include "selfsizingmainwindow.h"
#include <bitsharesguiprecomp.h>
#include <QtCore>
#include <QtGui>


SelfSizingMainWindow::SelfSizingMainWindow(QWidget *parent) :
    QMainWindow(parent)
{
}

// this should be called in constructor of derived classes after call to setupUi
void SelfSizingMainWindow::readSettings()
{
    QSettings settings("Invictus Innovations","BitSharesGUI");
    settings.beginGroup(windowTitle());
    restoreGeometry(settings.value("geometry").toByteArray());
    restoreState(settings.value("state").toByteArray(),VERSIONNUM);
    settings.endGroup();
}

void SelfSizingMainWindow::writeSettings()
{
    QSettings settings("Invictus Innovations","BitSharesGUI");
    settings.beginGroup(windowTitle());
    settings.setValue("geometry", saveGeometry());
    settings.setValue("state", saveState(VERSIONNUM));
    settings.endGroup();
}

void SelfSizingMainWindow::closeEvent(QCloseEvent *event)
{
    if (okToContinue())
        {
        writeSettings();
        event->accept();
        }
    else
        {
        event->ignore();
        }
}
