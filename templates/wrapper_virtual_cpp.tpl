#include "virtualwrapper{$imitator}.h"
#include <QTcpSocket>
#include <QFile>
#include <QIODevice>
#include <iostream>

_{$imitator}VirtualWrapper::_{$imitator}VirtualWrapper(QString panelname) : IVirtualWrapper(panelname)
{


}

void _{$imitator}VirtualWrapper::processParam(QString name, QVariant value)
{
    qDebug("**  wropper->process param %s %s", qPrintable(name), qPrintable(value.toString()));
	_icompsdisp->setIndication("IND", name, value);

}


extern "C" Q_DECL_EXPORT _{$imitator}VirtualWrapper* createWrapper(QString panelname)
{
    return new _{$imitator}VirtualWrapper(panelname);
}
