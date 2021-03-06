/***************************************************************************
    qgsmaptoolzoom.h  -  map tool for zooming
    ----------------------
    begin                : January 2006
    copyright            : (C) 2006 by Martin Dobias
    email                : wonder.sk at gmail dot com
 ***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef QGSMAPTOOLZOOM_H
#define QGSMAPTOOLZOOM_H

#include "qgsmaptool.h"
#include <QRect>
#include "qgis_gui.h"

class QgsRubberBand;

/** \ingroup gui
 * A map tool for zooming into the map.
 * @see QgsMapTool
 */
class GUI_EXPORT QgsMapToolZoom : public QgsMapTool
{
    Q_OBJECT

  public:
    //! constructor
    QgsMapToolZoom( QgsMapCanvas* canvas, bool zoomOut );
    ~QgsMapToolZoom();

    virtual Flags flags() const override { return QgsMapTool::Transient; }
    virtual void canvasMoveEvent( QgsMapMouseEvent* e ) override;
    virtual void canvasPressEvent( QgsMapMouseEvent* e ) override;
    virtual void canvasReleaseEvent( QgsMapMouseEvent* e ) override;
    virtual void deactivate() override;

  protected:
    //! stores actual zoom rect
    QRect mZoomRect;

    //! indicates whether we're zooming in or out
    bool mZoomOut;

    //! Flag to indicate a map canvas drag operation is taking place
    bool mDragging;

    QgsRubberBand* mRubberBand = nullptr;
};

#endif
