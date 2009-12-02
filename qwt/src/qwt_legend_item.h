/* -*- mode: C++ ; c-file-style: "stroustrup" -*- *****************************
 * Qwt Widget Library
 * Copyright (C) 1997   Josef Wilgen
 * Copyright (C) 2002   Uwe Rathmann
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the Qwt License, Version 1.0
 *****************************************************************************/

// vim: expandtab

#ifndef QWT_LEGEND_ITEM_H
#define QWT_LEGEND_ITEM_H

#include "qwt_global.h"
#include "qwt_legend.h"
#include "qwt_text.h"
#include "qwt_text_label.h"

class QPainter;
class QPen;
class QwtSymbol;

class QWT_EXPORT QwtLegendItem: public QwtTextLabel
{
    Q_OBJECT
public:
    /*!
       \brief Identifier mode

       Default is ShowLine | ShowText
       \sa identifierMode(), setIdentifierMode()
     */

    enum IdentifierMode
    {
        NoIdentifier = 0,
        ShowLine = 1,
        ShowSymbol = 2,
        ShowText = 4
    };

    explicit QwtLegendItem(QWidget *parent = 0);
    virtual ~QwtLegendItem();

    void setItemMode(QwtLegend::LegendItemMode);
    QwtLegend::LegendItemMode itemMode() const;

    virtual void setText(const QwtText &);

    void setIdentifierColor(const QColor &);
	QColor identifierColor() const;

    void setSpacing(int spacing);
    int spacing() const;

    void setIdentifierMode(int);
    int identifierMode() const;

    void setIdentifierWidth(int width);
    int identifierWidth() const;

    virtual QSize sizeHint() const;

    bool isChecked() const;

    virtual void drawIdentifier(QPainter *, const QRect &) const;
    virtual void drawItem(QPainter *p, const QRect &) const; 

public slots:
    void setChecked(bool on);

signals: 
    //! Signal, when the legend item has been clicked
    void clicked();

    //! Signal, when the legend item has been pressed
    void pressed();
    
    //! Signal, when the legend item has been relased
    void released();
    
    //! Signal, when the legend item has been toggled
    void checked(bool);

protected:
    void setDown(bool);
    bool isDown() const;
    
    virtual void paintEvent(QPaintEvent *);
    virtual void mousePressEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);
    virtual void keyPressEvent(QKeyEvent *);
    virtual void keyReleaseEvent(QKeyEvent *);
    
private:
    class PrivateData;
    PrivateData *d_data;
};

/*!
  \brief A legend item for curves

  QwtLegendCurveItem represents a curve on a legend.
  It displays an curve identifier with an explaining text.
  The identifier might be a combination of curve symbol and line.
  In readonly mode it behaves like a label, otherwise like 
  an unstylish push button.

  \sa QwtLegend, QwtPlotCurve
*/
class QWT_EXPORT QwtLegendCurveItem: public QwtLegendItem
{
    Q_OBJECT
public:
   
    explicit QwtLegendCurveItem(QWidget *parent = 0);
    explicit QwtLegendCurveItem(const QwtSymbol &, const QPen &,
        const QwtText &, QWidget *parent = 0);
    virtual ~QwtLegendCurveItem();

    void setSymbol(const QwtSymbol &);
    const QwtSymbol& symbol() const;

    void setCurvePen(const QPen &);
    const QPen& curvePen() const;

    virtual void drawIdentifier(QPainter *, const QRect &) const;

private:
    class PrivateData;
    PrivateData *d_data;
};

#endif // QWT_LEGEND_ITEM_H