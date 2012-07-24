/* Copyright 2003 Kjetil S. Matheussen

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA. */

#ifdef USE_QT3
#include <qapplication.h>
#include <qpixmap.h>
#include <qmenubar.h>
#include <qpointarray.h>
#include <qlabel.h>
#endif

#ifdef USE_QT4
//Added by qt3to4:
#include <QWidget>
#include <QCustomEvent>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QWheelEvent>
#include <QCloseEvent>
#include <Q3PointArray>
#include <QFrame>
#include <QLabel>
#include <QMenuBar>
#include <QApplication>
#endif

#ifdef USE_QT3
# define Q3PointArray QPointArray
# define Q3PopupMenu QPopupMenu
#endif


#define GFX_DONTSHRINK
#include "../common/nsmtracker.h"
#include "../common/windows_proc.h"

#include "../common/visual_proc.h"
#include "../common/visual_op_queue_proc.h"


// Don't paint on the frame.
#define XOFFSET 5
#define YOFFSET 2

class QMainWindow;
class QSplitter;

class EditorWidget : public QFrame
{
public:
  EditorWidget(QWidget *parent=0, const char *name=0 );
  ~EditorWidget();

#if USE_QT4
  const QPaintEngine* paintEngine();
#endif

    QColor     colors[16];				// color array
    QPixmap    *qpixmap;
    QPixmap    *cursorpixmap;

    //void timerEvent(QTimerEvent *);

    struct Tracker_Windows *window; // Not sure if this one is used.

    QMainWindow *main_window;

    QPainter *painter; // Set in paintEvent
    QPainter *qpixmap_painter; // Set in paintEvent
    QPainter *cursorpixmap_painter; // Set in paintEvent

    QFont font;

    //QFrame *status_frame;
    QLabel *status_label;

    QSplitter *xsplitter;
    QSplitter *ysplitter;

    int get_editor_width(){
      return this->width()-XOFFSET-2; // Fine tuned. No logical reason behind it. (2 is probably just the frame border width)
    }

    int get_editor_height(){
      return this->height()-YOFFSET-2; // Fine tuned. No logical reason behind it. (2 is probably just the frame border width)
    }

    QPointArray qpa;

protected:
    //    bool        event(QEvent *);
    void	paintEvent( QPaintEvent * );
#if 0
    void        keyPressEvent(QKeyEvent *);
    void        keyReleaseEvent(QKeyEvent *qkeyevent);
#endif
    void	mousePressEvent( QMouseEvent *);
    void	mouseReleaseEvent( QMouseEvent *);
    void	mouseMoveEvent( QMouseEvent *);
    void        resizeEvent( QResizeEvent *);
    void        closeEvent(QCloseEvent *);
    void        wheelEvent(QWheelEvent *);
    void        customEvent(QCustomEvent *);
};
