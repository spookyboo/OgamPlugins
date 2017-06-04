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

#ifndef OGAM_FILERESOURCE_PLUGIN_H
#define OGAM_FILERESOURCE_PLUGIN_H

#include <QtCore/qglobal.h>
#include "plugin_resource_interface.h"
#include "file_explorer_dockwidget.h"
#include "central_dockwidget.h"

// Define import/export
#if defined(OGAM_FILERESOURCE_PLUGIN_LIBRARY)
#  define OGAM_FILERESOURCE_PLUGINSHARED_EXPORT Q_DECL_EXPORT
#else
#  define OGAM_FILERESOURCE_PLUGINSHARED_EXPORT Q_DECL_IMPORT
#endif

static const std::string FILE_RESOURCE_PLUGIN_NAME = "OgamFileResourcePlugin";
class AssetsDockWidget;
/****************************************************************************
 The OgamFileResourcePlugin is an implementation of the PluginInterface and
 provides access to assets on a file system
 ***************************************************************************/
class OGAM_FILERESOURCE_PLUGINSHARED_EXPORT OgamFileResourcePlugin : public PluginResourceInterface
{
    public:
        OgamFileResourcePlugin (AssetsDockWidget* assetsDockWidget);
        virtual ~OgamFileResourcePlugin (void) {}

        virtual const std::string& getName (void) const;
        virtual void install (void);
        virtual void initialise (void);
        virtual void shutdown (void);
        virtual void uninstall (void);
        virtual void resetWindowLayout (void);
        virtual void addResource (const AssetMetaData& assetMetaData);

    private:
        AssetsDockWidget* mAssetsDockWidget;
        QWidget* mMainWidget;
        QMainWindow* mInnerMain;
        CentralDockWidget* mCentralDockWidget;
        FileExplorerDockWidget* mFileExplorerDockWidget;
};

static OgamFileResourcePlugin* plugin;

/****************************************************************************
 Provide external access by the Ogam application:
 The function 'createPlugin' creates a static instance of OgamFileResourcePlugin
 and returns it's pointer
 ***************************************************************************/
extern "C" OGAM_FILERESOURCE_PLUGINSHARED_EXPORT PluginInterface* createPlugin (AssetsDockWidget* assetsDockWidget)
{
    plugin = new OgamFileResourcePlugin(assetsDockWidget);
    return plugin;
}

/****************************************************************************
 Provide external access by the Ogam application:
 The function 'deletePlugin' deletes the static instance of OgamFileResourcePlugin
 ***************************************************************************/
extern "C" OGAM_FILERESOURCE_PLUGINSHARED_EXPORT void deletePlugin (void)
{
    delete plugin;
}

#endif
