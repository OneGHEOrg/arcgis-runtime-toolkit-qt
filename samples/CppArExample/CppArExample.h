/*******************************************************************************
 *  Copyright 2012-2019 Esri
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ******************************************************************************/

#ifndef CppArExample_H
#define CppArExample_H

#include <QObject>
#include "ArcGISArView.h"

namespace Esri {
namespace ArcGISRuntime {
class Scene;
class SceneQuickView;
class GraphicsOverlay;
} // ArcGISRuntime namespace
} // Esri namespace

class CppArExample : public QObject
{
  Q_OBJECT

  Q_PROPERTY(Esri::ArcGISRuntime::Toolkit::ArcGISArView* arcGISArView READ arcGISArView WRITE setArcGISArView
             NOTIFY arcGISArViewChanged)
  Q_PROPERTY(Esri::ArcGISRuntime::SceneQuickView* sceneView READ sceneView WRITE setSceneView NOTIFY sceneViewChanged)
  Q_PROPERTY(bool screenToLocationMode MEMBER m_screenToLocationMode NOTIFY screenToLocationModeChanged)
  Q_PROPERTY(bool tabletopMode MEMBER m_tabletopMode NOTIFY tabletopModeChanged)
  Q_PROPERTY(bool waitingInitialization MEMBER m_waitingInitialization NOTIFY waitingInitializationChanged)

public:
  explicit CppArExample(QObject* parent = nullptr);
  ~CppArExample() override;

  Esri::ArcGISRuntime::Toolkit::ArcGISArView* arcGISArView() const;
  void setArcGISArView(Esri::ArcGISRuntime::Toolkit::ArcGISArView* arcGISArView);

  Esri::ArcGISRuntime::SceneQuickView* sceneView() const;
  void setSceneView(Esri::ArcGISRuntime::SceneQuickView* sceneView);

  Q_INVOKABLE void updateOriginCamera(double latitude, double longitude, double altitude, double heading);

  Q_INVOKABLE void showPointCloud(bool visible);
  Q_INVOKABLE void showPlanes(bool visible);

  Q_INVOKABLE void createEmptyScene();
  Q_INVOKABLE void createStreetsScene();
  Q_INVOKABLE void createImageryScene();
  Q_INVOKABLE void createFullScaleTestScene();

  Q_INVOKABLE void createYosemiteScene();
  Q_INVOKABLE void createBorderScene();
  Q_INVOKABLE void createBrestScene();
  Q_INVOKABLE void createBerlinScene();
  Q_INVOKABLE void createTabletopTestScene();

signals:
  void arcGISArViewChanged();
  void sceneViewChanged();
  void screenToLocationModeChanged();
  void tabletopModeChanged();
  void waitingInitializationChanged();

private slots:
  void onTouched(QMouseEvent& event);

private:
  Q_DISABLE_COPY(CppArExample)

  Esri::ArcGISRuntime::GraphicsOverlay* getOrCreateGraphicsOverlay() const;
  void createSurfaceWithElevation() const;
  void changeScene(bool withLocationDataSource = false);

  Esri::ArcGISRuntime::Toolkit::ArcGISArView* m_arcGISArView = nullptr;
  Esri::ArcGISRuntime::SceneQuickView* m_sceneView = nullptr;
  Esri::ArcGISRuntime::Scene* m_scene = nullptr;

  // Screen to location properties
  bool m_screenToLocationMode = false;
  QMetaObject::Connection m_touchedConnection;
  
  // The origin camera set when the scene is created.
  Esri::ArcGISRuntime::Camera m_originCamera;

  // Properties for messages
  bool m_tabletopMode = false;
  bool m_waitingInitialization = false;

  QMetaObject::Connection m_locationDataSourceConnection;
};

#endif // CppArExample_H
