from multiprocessing.connection import Listener as l
import cv2 as cv
import numpy as np
import base64
from PyQt5.QtWidgets import *
from PyQt5 import uic

from PyQt5.QtGui import *
from PyQt5.QtCore import *

import sys

class UI(QMainWindow):
    def __init__(self):
        super(UI,self).__init__()
        uic.loadUi("VortexGUI.ui",self)
        
        self.flag=False
        self.count=0

        self.centralWidget= self.findChild(QWidget, "centralwidget")
        self.setCentralWidget(self.centralWidget)

        self.background=self.findChild(QLabel,"background")
        self.DownArrow = self.findChild(QLabel, "DownArrow")
        self.UpArrow = self.findChild(QLabel, "UpArrow")
        self.UpArc = self.findChild(QLabel,"UpArc")
        self.DownArc= self.findChild(QLabel, "DownArc")
        self.VGrapper = self.findChild(QLabel, "VGrapper")
        self.lHGraaper = self.findChild(QLabel, "lHGraaper")
        self.Down = self.findChild(QLabel, "Down")
        self.UP = self.findChild(QLabel, "UP")
        self.Right = self.findChild(QLabel, "Right")
        self.Left = self.findChild(QLabel, "Left")
        self.C1 = self.findChild(QLabel, "Camra1")
        self.mode = self.findChild(QLabel, "label_26")
        self.timer = self.findChild(QLabel, "timer")
        self.BAuto = self.findChild(QPushButton, "Autonmous")
        self.BDepth = self.findChild(QPushButton, "DepthHold")
        self.BStablize = self.findChild(QPushButton, "Stablize")
        self.BManual = self.findChild(QPushButton, "Manual")
        self.BStart = self.findChild(QPushButton, "Start")
        self.BStop = self.findChild(QPushButton, "Stop")
        self.BRest = self.findChild(QPushButton, "Rest")

        self.BAuto.clicked.connect(lambda : self.ChangeMode("Autonmous"))
        self.BDepth.clicked.connect(lambda : self.ChangeMode("Depth Hold"))
        self.BStablize.clicked.connect(lambda : self.ChangeMode("Stablize"))
        self.BManual.clicked.connect(lambda : self.ChangeMode("Manual"))
        self.BStart.clicked.connect(self.Startt)
        self.BStop.clicked.connect(self.Pause)
        self.BRest.clicked.connect(self.Reset)

        self.time = QTimer(self)
        self.time.timeout.connect(self.showTime)
        self.time.start(100)

        self.background.setStyleSheet("background-image : url(icons/a.jpg);background-repeat: no-repeat; background-position: center;")
        self.background.setPixmap(QPixmap('icons/a.png'))
        self.DownArrow.setPixmap( QPixmap('icons/downward-arrowred.png'))
        self.UpArrow.setPixmap(QPixmap('icons/upward-arrowred.png'))
        self.UpArc.setPixmap(QPixmap('icons/cwred.png'))
        self.DownArc.setPixmap(QPixmap('icons/ccwred.png'))
        self.VGrapper.setPixmap(QPixmap('icons/grapper-open.png'))
        self.lHGraaper.setPixmap(QPixmap('icons/grapper-open-horizontal.png'))
        self.Down.setPixmap(QPixmap('icons/bckwrd-arrowred.png'))
        self.UP.setPixmap(QPixmap('icons/frwrd-arrowred.png'))
        self.Right.setPixmap(QPixmap('icons/right-arrowred.png'))
        self.Left.setPixmap(QPixmap('icons/left-arrowred.png'))

        self.DownArrow.setStyleSheet("QLabel::hover""{""background-color : lightgreen;""}")
        self.UpArrow.setStyleSheet("QLabel::hover""{""background-color : lightgreen;""}")
        self.UpArc.setStyleSheet("QLabel::hover""{""background-color : lightgreen;""}")
        self.DownArc.setStyleSheet("QLabel::hover""{""background-color : lightgreen;""}")
        self.VGrapper.setStyleSheet("QLabel::hover""{""background-color : lightgreen;""}")
        self.lHGraaper.setStyleSheet("QLabel::hover""{""background-color : lightgreen;""}")
        self.Down.setStyleSheet("QLabel::hover""{""background-color : lightgreen;""}")
        self.UP.setStyleSheet("QLabel::hover""{""background-color : lightgreen;""}")
        self.Right.setStyleSheet("QLabel::hover""{""background-color : lightgreen;""}")
        self.Left.setStyleSheet("QLabel::hover""{""background-color : lightgreen;""}")
        

        self.Worker1 = Worker1()
        self.Worker1.start()
        self.Worker1.ImageUpdate.connect(self.ImageUpdateSlot)
        self.show()
    def showTime(self):
        if self.flag:
            self.count+= 1
        text = str(self.count / 10)
        self.timer.setText(text)
    
    def Startt(self):
        self.flag = True
  
    def Pause(self):
        self.flag = False
  
    def Reset(self):
        self.flag = False
        self.count = 0
        self.timer.setText(str(self.count))

    def ImageUpdateSlot(self, Image):
        self.C1.setPixmap(QPixmap.fromImage(Image))
    
    def ChangeMode(self,modee):
        self.mode.setText(modee)

    def keyPressEvent(self, event):
        if event.key() == Qt.Key_Up:
            self.UpArrow.setPixmap(QPixmap('icons/upward-arrow.png'))
        else:
            self.UpArrow.setPixmap(QPixmap('icons/upward-arrowred.png'))
        if event.key() == Qt.Key_Down:
            self.DownArrow.setPixmap(QPixmap('icons/downward-arrow.png'))
        else:
            self.DownArrow.setPixmap(QPixmap('icons/downward-arrowred.png'))
        if event.key() == Qt.Key_Right:
            self.UpArc.setPixmap(QPixmap('icons/cw.png'))
        else:
            self.UpArc.setPixmap(QPixmap('icons/cwred.png'))
        if event.key() == Qt.Key_Left:
            self.DownArc.setPixmap(QPixmap('icons/ccw.png'))
        else:
            self.DownArc.setPixmap(QPixmap('icons/ccwred.png'))
        if event.key() == Qt.Key_W:
            self.UP.setPixmap(QPixmap('icons/frwrd-arrow.png'))
        else:
            self.UP.setPixmap(QPixmap('icons/frwrd-arrowred.png'))
        if event.key() == Qt.Key_S:
            self.Down.setPixmap(QPixmap('icons/bckwrd-arrow.png'))
        else:
            self.Down.setPixmap(QPixmap('icons/bckwrd-arrowred.png'))
        if event.key() == Qt.Key_D:
            self.Right.setPixmap(QPixmap('icons/right-arrow.png'))
        else:
            self.Right.setPixmap(QPixmap('icons/right-arrowred.png'))
        if event.key() == Qt.Key_A:
            self.Left.setPixmap(QPixmap('icons/left-arrow.png'))
        else:
            self.Left.setPixmap(QPixmap('icons/left-arrowred.png'))
        if event.key() == Qt.Key_E:
            self.VGrapper.setPixmap(QPixmap('icons/grapper-open.png'))
        if event.key() == Qt.Key_Q:
            self.VGrapper.setPixmap(QPixmap('icons/grapper-close.png'))
        if event.key() == Qt.Key_X:
            self.lHGraaper.setPixmap(QPixmap('icons/grapper-open-horizontal.png'))
        if event.key() == Qt.Key_Z:
            self.lHGraaper.setPixmap(QPixmap('icons/grapper-close-horizontal.png'))


class Worker1(QThread):
    ImageUpdate = pyqtSignal(QImage)
    def run(self):
        self.ThreadActive = True
        self.adrr = ('0.0.0.0',12345)
        self.lis = l(self.adrr, authkey=b'bsg')
        self.conn = self.lis.accept()
        while self.ThreadActive:
            packet = self.conn.recv()
            data = base64.b64decode(packet,' /')
            npdata = np.fromstring(data,dtype=np.uint8)
            frame = cv.imdecode(npdata,1)
            frame = cv.flip(frame, 1)
            converted = QImage(frame, frame.shape[1],
                            frame.shape[0], frame.shape[1] * 3,QImage.Format_RGB888).rgbSwapped()
            Pic = converted.scaled(640, 480, Qt.KeepAspectRatio)
            self.ImageUpdate.emit(Pic)



app = QApplication(sys.argv)
UiWindow = UI()
app.exec_()


