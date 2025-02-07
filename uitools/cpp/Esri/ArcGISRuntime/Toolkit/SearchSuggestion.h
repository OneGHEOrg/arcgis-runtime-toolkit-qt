/*******************************************************************************
 *  Copyright 2012-2021 Esri
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
#ifndef ESRI_ARCGISRUNTIME_TOOLKIT_SEARCHSUGGESTION_H
#define ESRI_ARCGISRUNTIME_TOOLKIT_SEARCHSUGGESTION_H

// Toolkit headers
#include "SearchSourceInterface.h"

// ArcGISRuntime headers
#include <SuggestResult.h>

// Qt headers
#include <QObject>
#include <QString>
#include <QUrl>

namespace Esri {
namespace ArcGISRuntime {
namespace Toolkit {

  class SearchSuggestion: public QObject
  {
    Q_OBJECT
    Q_PROPERTY(QString displayTitle READ displayTitle NOTIFY suggestResultChanged)
    Q_PROPERTY(QString displaySubtitle READ displaySubtitle WRITE setDisplaySubtitle NOTIFY displaySubtitleChanged)
    Q_PROPERTY(QUrl markerImageUrl READ markerImageUrl NOTIFY markerImageUrlChanged)
    Q_PROPERTY(SearchSourceInterface* owningSource READ owningSource WRITE setOwningSource NOTIFY owningSourceChanged)
    Q_PROPERTY(bool collection READ isCollection NOTIFY suggestResultChanged)
  public:
    Q_INVOKABLE SearchSuggestion(QObject* parent = nullptr);

    ~SearchSuggestion() override;

    QString displayTitle() const;

    QString displaySubtitle() const;
    void setDisplaySubtitle(QString displaySubtitle);

    QUrl markerImageUrl() const;

    SearchSourceInterface* owningSource();
    void setOwningSource(SearchSourceInterface* owningInterface);

    const SuggestResult& suggestResult() const;
    void setSuggestResult(SuggestResult suggestResult);

    bool isCollection() const;

  signals:
    void displaySubtitleChanged();
    void markerImageUrlChanged();
    void owningSourceChanged();
    void suggestResultChanged();

  private:
    QString m_displaySubtitle;
    QUrl m_markerImageUrl;
    SearchSourceInterface* m_owningSource;
    SuggestResult m_suggestResult;
  };

} // Toolkit
} // ArcGISRuntime
} // Esri


#endif // ESRI_ARCGISRUNTIME_TOOLKIT_SEARCHSUGGESTION_H
