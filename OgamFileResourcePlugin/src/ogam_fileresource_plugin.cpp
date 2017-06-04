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

#include "file_resource_constants.h"
#include "ogam_fileresource_plugin.h"
#include "assets_dockwidget.h"
#include <QHBoxLayout>
#include <QMessageBox>

//****************************************************************************/
OgamFileResourcePlugin::OgamFileResourcePlugin (AssetsDockWidget* assetsDockWidget) :
    mAssetsDockWidget(assetsDockWidget)
{
    // Create the main widget that is added to the assetsDockWidget's tab
    mMainWidget = new QWidget();

    // Add a main window
    QHBoxLayout* mainLayout = new QHBoxLayout;
    mInnerMain = new QMainWindow();
    mainLayout->addWidget(mInnerMain);
    mMainWidget->setLayout(mainLayout);

    // Create DockWidgets in the main window
    mCentralDockWidget = new CentralDockWidget("Main", mInnerMain);
    mCentralDockWidget->setPlugin(this); // Add reference to this plugin
    mFileExplorerDockWidget = new FileExplorerDockWidget("File system", mInnerMain);
    mFileExplorerDockWidget->setPlugin(this); // Add reference to this plugin
    mFileExplorerDockWidget->setCentralDockWidget(mCentralDockWidget); // Add reference to the central widget
    mInnerMain->addDockWidget(Qt::RightDockWidgetArea, mFileExplorerDockWidget);
    mInnerMain->setCentralWidget(mCentralDockWidget);
}

//****************************************************************************/
const std::string& OgamFileResourcePlugin::getName (void) const
{
    return FILE_RESOURCE_PLUGIN_NAME;
}

//****************************************************************************/
void OgamFileResourcePlugin::install (void)
{
    mAssetsDockWidget->addWidget(mMainWidget, PLUGIN_ICON_PATH + PLUGIN_ICON_FOLDER, "Filesystem");
}

//****************************************************************************/
void OgamFileResourcePlugin::initialise (void)
{
}

//****************************************************************************/
void OgamFileResourcePlugin::shutdown (void)
{
}

//****************************************************************************/
void OgamFileResourcePlugin::uninstall (void)
{
}

//****************************************************************************/
void OgamFileResourcePlugin::resetWindowLayout (void)
{
    mCentralDockWidget->show();
    mInnerMain->setCentralWidget(mCentralDockWidget);
    mFileExplorerDockWidget->show();
    mInnerMain->addDockWidget(Qt::RightDockWidgetArea, mFileExplorerDockWidget);
}

//****************************************************************************/
void OgamFileResourcePlugin::addResource (const AssetMetaData& assetMetaData)
{
    // TODO
}
