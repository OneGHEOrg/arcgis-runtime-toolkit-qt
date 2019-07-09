/*******************************************************************************
 *  Copyright 2012-2018 Esri
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

#include "ArcGISArView.h"
#include "TransformationMatrix.h"

/*!
  \class Esri::ArcGISRuntime::Toolkit::ArcGISArView
  \ingroup AR
  \inmodule ArcGISQtToolkit
  \since Esri::ArcGISRuntime 100.6
  \brief ...
  \sa {AR}
 */

using namespace Esri::ArcGISRuntime;
using namespace Esri::ArcGISRuntime::Toolkit;

/*!
  \brief A constructor that accepts an optional \a parent.
 */
ArcGISArView::ArcGISArView(QQuickItem* parent):
  ArcGISArViewInterface(parent)
{
}

/*!
  \brief A constructor that accepts an optional \a parent.
 */
ArcGISArView::ArcGISArView(int renderVideoFeed, QQuickItem* parent):
  ArcGISArViewInterface(renderVideoFeed, parent)
{
}

/*!
   \brief The destructor.
 */
ArcGISArView::~ArcGISArView()
{
}

/*!
  \brief ...
 */
Camera ArcGISArView::originCamera() const
{
  return Camera(m_originCamera);
}

/*!
  \brief ...
 */
void ArcGISArView::setOriginCamera(const Camera& originCamera)
{
  if (m_originCamera == originCamera)
    return;

  m_originCamera = originCamera;
  emit originCameraChanged();
}

/*!
  \brief ...
 */
SceneQuickView* ArcGISArView::sceneView() const
{
  return m_sceneView;
}

/*!
  \brief ...
 */
void ArcGISArView::setSceneView(SceneQuickView* sceneView)
{
  if (sceneView == m_sceneView)
    return;

  m_sceneView = sceneView;
  m_sceneView->setSpaceEffect(SpaceEffect::Transparent);
  m_sceneView->setAtmosphereEffect(AtmosphereEffect::None);
  m_sceneView->setParent(this);
  emit sceneViewChanged();

  startTracking();
}

/*!
  \brief ...
 */
Point ArcGISArView::arScreenToLocation(const Point& /*screenPoint*/) const
{
  return Point();
}

void ArcGISArView::updateCamera()
{
  if (m_originCamera.isEmpty())
  {
    Camera camera = m_sceneView->currentViewpointCamera();
    m_originCamera = camera; // Camera(camera.location(), camera.heading(), 90, 0);
  }

//  TransformationMatrix* tm = static_cast<TransformationMatrix*>(m_arWrapper->transformationMatrix());
//  TransformationMatrix matrix = m_originCamera.transformationMatrix().addTransformation(tm);
//  m_sceneView->setViewpointCamera(Camera(matrix));
}

// signals

/*!
  \fn void ArcGISArView::originCameraChanged();
  \brief Signal emitted when the \l originCamera property changes.
 */
