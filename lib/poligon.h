/// @file poligon.h
/// @brief Заголовочный файл библиотеки 
/// содержит определения типов данных, структуры, прототипы функций, перечисления, макросы препроцессора.
//#pragma once
#ifndef POLIGON_POLIGON_H
#define POLIGON_POLIGON_H
#include<opencv2/opencv.hpp>
#include<vector>
#include<math.h>
/// @struct Color
/// @brief Структура обозначающая определенный цвет.
/// 
/// Используется для того чтобы обозначить наиболее часто используемые цвета в программе.
struct Color
{
    /// @brief cv::Scalar Класс шаблонов для 4-элементного вектора, производного от Vec.
    cv::Scalar color{ 0,0,0 };
    /// @brief Конструктор копии.
    /// @param color cv::Scalar Класс шаблонов для 4-элементного вектора, производного от Vec.
    Color(cv::Scalar color)
        :color(color) {}
};
/// @brief Голубой цвет.
/// @param cv::Scalar Класс шаблонов для 4-элементного вектора, производного от Vec.
/// @return struct Color
const Color Blue(cv::Scalar(255, 0, 0));
/// @brief Зеленый цвет.
/// @param cv::Scalar Класс шаблонов для 4-элементного вектора, производного от Vec.
/// @return struct Color
const Color Green(cv::Scalar(0, 255, 0));
/// @brief Красный цвет.
/// @param cv::Scalar Класс шаблонов для 4-элементного вектора, производного от Vec.
/// @return struct Color
const Color Red(cv::Scalar(0, 0, 255));
/// @class CPoint
/// @brief Класс описывающий объект точка. 
class CPoint {
public:
    /// @brief Координата x
    int x{ -1 };
    /// @brief Координата y
    int y{ -1 };
    /// @brief Радиус точки.
    int radius{ 2 };
    /// @brief Параметр используемый для заливки точки, так как точка рисуется через окружность.
    int thickness{ -1 };
    /// @brief Конструктор точки по умолчанию.
    /// Создает экземпляр класса.
    CPoint() = default;
    /// @brief Конструктор принимающий координаты точки.
    /// @param x координата.
    /// @param y координата.
    CPoint(int x, int y);
    /// @brief Конструктор копии принимающий экземпляр класса CPoint
    /// @param a экземпляр класса CPoint
    CPoint(const CPoint& a);
    /// @brief Конструктор копии использующий встроенный класс cv::Point
    /// @param a экземпляр класса cv::Point
    CPoint(const cv::Point& a);
    /// @brief Деструктор по умолчанию.
    ~CPoint() = default;
    /// @brief Функция для отрисовки точки.
    /// @param imeg cv::Mat n-мерный класс плотных массивов.
    void DrawPoint(cv::Mat imeg);
    /// @brief Функция для отрисовки точки, принимающий в качестве параметра цвет.
    /// @param imeg cv::Mat n-мерный класс плотных массивов.
    /// @param cv::Scalar Класс шаблонов для 4-элементного вектора, производного от Vec.
    void DrawPoint(cv::Mat imeg, cv::Scalar color);
    /// @brief Оператор сравнения "Равно".
    /// @return bool
    const bool operator == (const CPoint p);
    /// @brief Оператор сравнения "Не равно".
    /// @return bool
    const bool operator != (const CPoint p);
    /// @brief Функция для записи точки.
    /// @param ostrm Выходной поток.
    /// @return std::ostream Выходной поток.
    std::ostream& writeTo(std::ostream& ostrm) const;
    /// @brief Функция для чтения точки.
    /// @param istrm Входной поток.
    /// @return std::istream Входной поток.
    std::istream& readFrom(std::istream& istrm);
};

/// @brief Метод проверяющий наличие точки в векторе.
/// @param p точка которая ищется в векторе.
/// @param points векотр в котором проиходит поиск.
/// @return bool
bool compP(CPoint p, std::vector<CPoint> points);
/// @class Line
/// @brief Класс описывающий объект линия.
class Line {
public:
    /// @brief Точка A граница отрезка.
    CPoint A{ -1,-1 };
    /// @brief Точка B граница отрезка.
    CPoint B{ -1,-1 };
    /// @brief Толщина линии.
    int thickness{ -1 };
    /// @brief Тип линии.
    int linetype{ 8 };
    /// @brief Количество дробных битов в координатах точки.
    int shift{ 0 };
    /// @brief Конструктор линии по умолчанию.
    Line() = default;
    /// @brief Деструктор точки по умолчанию.
    ~Line() = default;
    /// @brief Конструктор принимающий границы отрезка.
    /// @param A граница отрезка.
    /// @param B граница отрезка.
    Line(CPoint A, CPoint B);
    /// @brief Конструктор принимающий границы отрезка.
    /// @param A граница отрезка.
    /// @param B граница отрезка.
    /// @param thickness толщина линии.
    Line(CPoint A, CPoint B, int thickness);
    /// @brief Конструктор принимающий границы отрезка.
    /// @param A граница отрезка.
    /// @param B граница отрезка.
    /// @param thickness толщина линии.
    /// @param linetype тип линии.
    Line(CPoint A, CPoint B, int thickness, int linetype);
    /// @brief Конструктор принимающий границы отрезка.
    /// @param A граница отрезка.
    /// @param B граница отрезка.
    /// @param thickness толщина линии.
    /// @param linetype тип линии.
    /// @param shift количество дробных битов в координатах точки.
    Line(CPoint A, CPoint B, int thickness, int linetype, int shift);
    /// @brief Конструктор копии.
    /// @param A объект class Line.
    Line(const Line& A);
    /// @brief Функция для отрисовки линии.
    /// @param imeg cv::Mat n-мерный класс плотных массивов.
    void DrawLine(cv::Mat imeg);
    /// @brief Функция для отрисовки линии.
    /// @param imeg cv::Mat n-мерный класс плотных массивов.
    /// @param color cv::Scalar Класс шаблонов для 4-элементного вектора, производного от Vec.
    void DrawLine(cv::Mat imeg, cv::Scalar color);
    /// @brief Метод для нахождения длины линии.
    /// @return Целое значение длины линии.
    int Lenght();
};

/// @brief Функция проверяющая существование точки пересечения двух линий.
/// @param A Line Класс описывающий объект линия.
/// @param B Line Класс описывающий объект линия.
/// @return bool
bool crossP(Line A, Line B);
/// @brief Функция проверяющая существование отрезка пересечения двух линий.
/// @param A Line Класс описывающий объект линия.
/// @param B Line Класс описывающий объект линия.
/// @return bool
bool crossLn(Line A, Line B);
/// @brief Векторное произведение.
/// @param A Line Класс описывающий объект линия.
/// @param B Line Класс описывающий объект линия.
/// @return int целое значение.
int vecpro(Line A, Line B);
/// @brief Функция находящая точку пересечения двух прямых.
/// @param A Line Класс описывающий объект линия.
/// @param B Line Класс описывающий объект линия.
/// @return CPoint Класс описывающий объект линия.
CPoint CrossPoint(Line A, Line B);
/// @brief Функция находящая отрезок пересечения двух прямых.
/// @param A Line Класс описывающий объект линия.
/// @param B Line Класс описывающий объект линия.
/// @return Line Класс описывающий объект линия.
Line CrossLine(Line A, Line B);
/// @brief Функция проверяющая вершины полигона на соответсвие гипотезам.
/// @param points вектор вершин полигона.
void check1(std::vector<CPoint> points);
/// @brief Функция проверяющая стороны полигона на соответсвие гипотезам.
/// @param lines вектор сторон полигона.
void check2(std::vector<Line> lines);
/// class Poligon
/// @brief Класс описывающий объект полигон.
class Poligon {
public:
    /// @brief Вектор содержащий множество точек полигона.
    std::vector<CPoint> points;
    /// @brief Вектор содержащий множество ребер полигона.
    std::vector<Line> lines;
    /// @brief Конструктор полигона по умолчанию.
    Poligon() = default;
    /// @brief Деструктор полигона по умолчанию.
    ~Poligon() = default;
    /// @brief Конструктор копии.
    /// @param P экземпляр класса Poligon.
    Poligon(const Poligon& P);
    /// @brief Конструктор принимающий вектор вершин полигона.
    /// @param cpoints Вектор содержащий множество точек полигона.
    Poligon(std::vector<CPoint> cpoints);
    /// @brief Конструктор принимающий вектор вершин полигона.
    /// @param cpoints Вектор содержащий множество точек cv::Point полигона .
    Poligon(std::vector<cv::Point> cpoints);
    /// @brief Функция для отрисовки вершин полигона.
    /// @param imeg cv::Mat n-мерный класс плотных массивов.
    /// @param color cv::Scalar Класс шаблонов для 4-элементного вектора, производного от Vec.
    void DrawPoints(cv::Mat imeg, cv::Scalar color);
    /// @brief Функция для отрисовки ребер полигона.
    /// @param imeg cv::Mat n-мерный класс плотных массивов.
    /// @param color cv::Scalar Класс шаблонов для 4-элементного вектора, производного от Vec.
    void DrawLines(cv::Mat imeg, cv::Scalar color);
    /// @brief Функция для отрисовки полигона.
    /// @param imeg cv::Mat n-мерный класс плотных массивов.
    /// @param color cv::Scalar Класс шаблонов для 4-элементного вектора, производного от Vec.
    void DrawPoligon(cv::Mat imeg, cv::Scalar color);
    /// @brief Функция для записи полигона.
    /// @param ostrm Выходной поток.
    /// @return std::ostream Выходной поток.
    std::ostream& writeTo(std::ostream& ostrm) const;
    /// @brief Функция для чтения полигона.
    /// @param istrm Входной поток.
    /// @return std::istream Входной поток.
    std::istream& readFrom(std::istream& istrm);
};
/// @brief Функция проверяющая находится ли точка внутри полигона.
/// @param P class Poligon Полигон для которого проходит проверка.
/// @param a class CPoint Точка которая проходит проверку.
/// @return bool
bool Interpoint(const Poligon P, const CPoint a);
/// @brief Функция для нахождения длины вектора
/// @param l class Line Класс описывающий объект линия.
/// @return double длину вектора
double veclen(Line l);
/// @brief Функция для нахождения косинуса угла между двумя прямыми
/// @param l1 class Line Класс описывающий объект линия.
/// @param l2 class Line Класс описывающий объект линия.
/// @return double косинус угла между векторами.
double angle(Line l1, Line l2);
/// @brief Функция для сортировки точек. 
/// Сортирует точки по возрастанию угла между горизонтальным вектором проведенным из вершины 
/// с наименьшей координатой y и векторами образованными вершиной с наименьшей координатой y и остальными вершинами полигона.
/// @param points Вектор содержащий множество точек полигона.
void sortPoint(std::vector<CPoint>& points);
/// @brief Функция для нахождения полигона пересечения двух полигонов.
/// @param A Полигон.
/// @param B Полигон.
/// @return Полигон пересечения.
Poligon Interseption(Poligon A, Poligon B);
#endif
