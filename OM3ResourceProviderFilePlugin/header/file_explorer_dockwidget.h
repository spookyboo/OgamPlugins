/****************************************************************************
**
** Copyright (C) 2017, Henry van Merode
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
****************************************************************************/

#ifndef FILE_EXPLORER_DOCWIDGET_H
#define FILE_EXPLORER_DOCWIDGET_H

#include <QtWidgets>
#include <QAction>
#include <QMessageBox>
#include <QMainWindow>
#include "tool_resourcetree_widget.h"
#include "plugin_resource_provider_interface.h"

QT_BEGIN_NAMESPACE
class QDockWidget;
QT_END_NAMESPACE

/****************************************************************************
 This class represents a DockWidget
 ***************************************************************************/
class CentralDockWidget;
class FileExplorerDockWidget : public QDockWidget
{
	Q_OBJECT

    public:
        FileExplorerDockWidget(const QString& title, QMainWindow* parent, Qt::WindowFlags flags = 0);
        ~FileExplorerDockWidget(void);

        /* Set the pointer to the plugin. This is used to communicate with the main OM3 application
         */
        void setPlugin (PluginResourceProviderInterface* plugin);

        /* Set the pointer to the central widget.
         */
        void setCentralDockWidget (CentralDockWidget* widget);

    private slots:
        void handleCustomContextMenuItemSelected(const QString& menuItemText, int resourceId);

    protected:
        void addDirectory (void);
        void removeDirectory (int resourceId);

    private:
        QtResourceTreeWidget* mResourceTreeWidget;
        PluginResourceProviderInterface* mPlugin;
        CentralDockWidget* mCentralDockWidget;
};

#endif

