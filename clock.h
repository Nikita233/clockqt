#ifndef CLOCK_H
#define CLOCK_H

#include <QtGui>
#include <math.h>

class Clock : public QWidget // наследуем наш класс от QWidget'а
{
	Q_OBJECT

public:
	Clock(QWidget *parent = 0);
	~Clock();
	void paintEvent(QPaintEvent *); // для рисования нам необходимо переопределить метод paintEvent
	void drawBase(QPainter &paint); // метод отрисовки циферблата
	void drawHours(QPainter &paint, double alpha); // метод отрисовки часовой стрелки
	void drawMinutes(QPainter &paint, double alpha); // ... минутной стрелки
	void drawSeconds(QPainter &paint, double alpha); // .. секундной стрелки
	void drawCenter(QPainter &paint); // отрисовка точки в центре
	void clear(QPainter &paint); // метод очистки экрана
	void timerEvent(QTimerEvent *); // таймер, чтобы каждую секунду обновлять изображение
	void initTime(); // метод инициализации времени и углов отклонения стрелок
	void recountTime(); // метод пересчета вермени
	QPair<double, double> getPoint(double nowX, double nowY, double alpha); // узнаем смещение стрелок

private:
	int Ox, Oy; // координаты центра
	int seconds, minutes, hours; // часы, минуты, секунды
	double upX, upY; // координаты верха
	double alphaSec, alphaMin, alphaHours; // углы отклонения стрелок
	bool first; // запускаем ли первый раз
};

#endif // CLOCK_H
