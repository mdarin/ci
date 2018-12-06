#ifndef IPANEL_H#define IPANEL_H
#include <QtCore/QtGlobal>
#define MAIN_FORM(xxx) extern "C" Q_DECL_EXPORT QWidget * createPanelForm() { return new xxx(); }
#endif // IPANEL_H
