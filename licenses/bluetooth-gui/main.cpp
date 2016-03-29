/*
* Bluetooth Demo
*
* Bluetooth demo application.
*
* Copyright (C) 2011 ProFUSION embedded systems
*
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*    Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the
*    documentation and/or other materials provided with the
*    distribution.
*
*    Neither the name of ProFUSION embedded systems nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/

#include "Keyboard.h"
#include "MainWindow.h"
#include "types.h"

#include <QtGui>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("Bluetooth Demo");
    app.setStyleSheet(
        "QScrollBar:vertical {"                                 \
        "    border: 2px solid grey;"                           \
        "    width: 36px;"                                      \
        "    background: rgba(255, 255, 255, 0);"               \
        "    height: 36px;"                                     \
        "    margin: 32px 0 32px 0;"                            \
        "}"                                                     \
        "QScrollBar::handle:vertical {"                         \
        "    background: rgb(181, 181, 181);"                   \
        "    min-height: 20px;"                                 \
        "}"                                                     \
        "QScrollBar::add-line:vertical {"                       \
        "    border: 2px solid grey;"                           \
        "    background: rgb(81, 81, 81);"                      \
        "    height: 30px;"                                     \
        "    subcontrol-position: bottom;"                      \
        "    subcontrol-origin: margin;"                        \
        "}"                                                     \
        "QScrollBar::sub-line:vertical {"                       \
        "    border: 2px solid grey;"                           \
        "    background: rgb(81, 81, 81);"                      \
        "    height: 30px;"                                     \
        "    subcontrol-position: top;"                         \
        "    subcontrol-origin: margin;"                        \
        "}"                                                     \
        "QScrollBar::up-arrow:vertical {"                       \
        "    border: 2px solid grey;"                           \
        "    width: 16px;"                                      \
        "    height: 16px;"                                     \
        "    border-image: url(:/images/go-up.png);"            \
        "}"                                                     \
        "QScrollBar::down-arrow:vertical {"                     \
        "    border: 2px solid grey;"                           \
        "    width: 16px;"                                      \
        "    height: 16px;"                                     \
        "    border-image: url(:/images/go-down.png);"          \
        "}"                                                     \
        "QScrollBar::add-page, QScrollBar::sub-page {"          \
        "    background: none;"                                 \
        "}"                                                     \
        "QScrollBar:horizontal {"                               \
        "    border: 2px solid grey;"                           \
        "    background: rgba(255, 255, 255, 0);"               \
        "    height: 36px;"                                     \
        "    margin: 0px 32px 0 32px;"                          \
        "}"                                                     \
        "QScrollBar::handle:horizontal {"                       \
        "    background: rgb(181, 181, 181);"                   \
        "    min-width: 20px;"                                  \
        "}"                                                     \
        "QScrollBar::add-line:horizontal {"                     \
        "    border: 2px solid grey;"                           \
        "    background: rgb(81, 81, 81);"                      \
        "    width: 30px;"                                      \
        "    subcontrol-position: right;"                       \
        "    subcontrol-origin: margin;"                        \
        "}"                                                     \
        "QScrollBar::sub-line:horizontal {"                     \
        "    border: 2px solid grey;"                           \
        "    background: rgb(81, 81, 81);"                      \
        "    width: 30px;"                                      \
        "    subcontrol-position: left;"                        \
        "    subcontrol-origin: margin;"                        \
        "}"                                                     \
        "QScrollBar::right-arrow:horizontal {"                  \
        "    border: 2px solid grey;"                           \
        "    width: 16px;"                                      \
        "    height: 16px;"                                     \
        "    border-image: url(:/images/go-next.png);"          \
        "}"                                                     \
        "QScrollBar:left-arrow:horizontal  {"                   \
        "    border: 2px solid grey;"                           \
        "    width: 16px;"                                      \
        "    height: 16px;"                                     \
        "    border-image: url(:/images/go-previous.png);"      \
        "}"                                                     \
        "QTreeView {"                                           \
        "    font: 20pt \"Arial\";"                             \
        "}");
    REGISTER_TYPES();

#if !defined(DEBUG)
    setenv("DBUS_SESSION_BUS_ADDRESS", "unix:path=/var/run/dbus/system_bus_socket", 1);
#endif

    MainWindow window;

#if defined(DEBUG)
    window.setMaximumSize(800,480);
    window.show();
#else
    window.showFullScreen();
#endif
    window.setWindowTitle(QApplication::translate("main", "Bluetooth Demo"));
    return app.exec();
}
