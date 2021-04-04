/// @file poligon.h
/// @brief ������������ ���� ���������� 
/// �������� ����������� ����� ������, ���������, ��������� �������, ������������, ������� �������������.
//#pragma once
#ifndef POLIGON_POLIGON_H
#define POLIGON_POLIGON_H
#include<opencv2/opencv.hpp>
#include<vector>
#include<math.h>
/// @struct Color
/// @brief ��������� ������������ ������������ ����.
/// 
/// ������������ ��� ���� ����� ���������� �������� ����� ������������ ����� � ���������.
struct Color
{
    /// @brief cv::Scalar ����� �������� ��� 4-����������� �������, ������������ �� Vec.
    cv::Scalar color{ 0,0,0 };
    /// @brief ����������� �����.
    /// @param color cv::Scalar ����� �������� ��� 4-����������� �������, ������������ �� Vec.
    Color(cv::Scalar color)
        :color(color) {}
};
/// @brief ������� ����.
/// @param cv::Scalar ����� �������� ��� 4-����������� �������, ������������ �� Vec.
/// @return struct Color
const Color Blue(cv::Scalar(255, 0, 0));
/// @brief ������� ����.
/// @param cv::Scalar ����� �������� ��� 4-����������� �������, ������������ �� Vec.
/// @return struct Color
const Color Green(cv::Scalar(0, 255, 0));
/// @brief ������� ����.
/// @param cv::Scalar ����� �������� ��� 4-����������� �������, ������������ �� Vec.
/// @return struct Color
const Color Red(cv::Scalar(0, 0, 255));
/// @class CPoint
/// @brief ����� ����������� ������ �����. 
class CPoint {
public:
    /// @brief ���������� x
    int x{ -1 };
    /// @brief ���������� y
    int y{ -1 };
    /// @brief ������ �����.
    int radius{ 2 };
    /// @brief �������� ������������ ��� ������� �����, ��� ��� ����� �������� ����� ����������.
    int thickness{ -1 };
    /// @brief ����������� ����� �� ���������.
    /// ������� ��������� ������.
    CPoint() = default;
    /// @brief ����������� ����������� ���������� �����.
    /// @param x ����������.
    /// @param y ����������.
    CPoint(int x, int y);
    /// @brief ����������� ����� ����������� ��������� ������ CPoint
    /// @param a ��������� ������ CPoint
    CPoint(const CPoint& a);
    /// @brief ����������� ����� ������������ ���������� ����� cv::Point
    /// @param a ��������� ������ cv::Point
    CPoint(const cv::Point& a);
    /// @brief ���������� �� ���������.
    ~CPoint() = default;
    /// @brief ������� ��� ��������� �����.
    /// @param imeg cv::Mat n-������ ����� ������� ��������.
    void DrawPoint(cv::Mat imeg);
    /// @brief ������� ��� ��������� �����, ����������� � �������� ��������� ����.
    /// @param imeg cv::Mat n-������ ����� ������� ��������.
    /// @param cv::Scalar ����� �������� ��� 4-����������� �������, ������������ �� Vec.
    void DrawPoint(cv::Mat imeg, cv::Scalar color);
    /// @brief �������� ��������� "�����".
    /// @return bool
    const bool operator == (const CPoint p);
    /// @brief �������� ��������� "�� �����".
    /// @return bool
    const bool operator != (const CPoint p);
    /// @brief ������� ��� ������ �����.
    /// @param ostrm �������� �����.
    /// @return std::ostream �������� �����.
    std::ostream& writeTo(std::ostream& ostrm) const;
    /// @brief ������� ��� ������ �����.
    /// @param istrm ������� �����.
    /// @return std::istream ������� �����.
    std::istream& readFrom(std::istream& istrm);
};

/// @brief ����� ����������� ������� ����� � �������.
/// @param p ����� ������� ������ � �������.
/// @param points ������ � ������� ��������� �����.
/// @return bool
bool compP(CPoint p, std::vector<CPoint> points);
/// @class Line
/// @brief ����� ����������� ������ �����.
class Line {
public:
    /// @brief ����� A ������� �������.
    CPoint A{ -1,-1 };
    /// @brief ����� B ������� �������.
    CPoint B{ -1,-1 };
    /// @brief ������� �����.
    int thickness{ -1 };
    /// @brief ��� �����.
    int linetype{ 8 };
    /// @brief ���������� ������� ����� � ����������� �����.
    int shift{ 0 };
    /// @brief ����������� ����� �� ���������.
    Line() = default;
    /// @brief ���������� ����� �� ���������.
    ~Line() = default;
    /// @brief ����������� ����������� ������� �������.
    /// @param A ������� �������.
    /// @param B ������� �������.
    Line(CPoint A, CPoint B);
    /// @brief ����������� ����������� ������� �������.
    /// @param A ������� �������.
    /// @param B ������� �������.
    /// @param thickness ������� �����.
    Line(CPoint A, CPoint B, int thickness);
    /// @brief ����������� ����������� ������� �������.
    /// @param A ������� �������.
    /// @param B ������� �������.
    /// @param thickness ������� �����.
    /// @param linetype ��� �����.
    Line(CPoint A, CPoint B, int thickness, int linetype);
    /// @brief ����������� ����������� ������� �������.
    /// @param A ������� �������.
    /// @param B ������� �������.
    /// @param thickness ������� �����.
    /// @param linetype ��� �����.
    /// @param shift ���������� ������� ����� � ����������� �����.
    Line(CPoint A, CPoint B, int thickness, int linetype, int shift);
    /// @brief ����������� �����.
    /// @param A ������ class Line.
    Line(const Line& A);
    /// @brief ������� ��� ��������� �����.
    /// @param imeg cv::Mat n-������ ����� ������� ��������.
    void DrawLine(cv::Mat imeg);
    /// @brief ������� ��� ��������� �����.
    /// @param imeg cv::Mat n-������ ����� ������� ��������.
    /// @param color cv::Scalar ����� �������� ��� 4-����������� �������, ������������ �� Vec.
    void DrawLine(cv::Mat imeg, cv::Scalar color);
    /// @brief ����� ��� ���������� ����� �����.
    /// @return ����� �������� ����� �����.
    int Lenght();
};

/// @brief ������� ����������� ������������� ����� ����������� ���� �����.
/// @param A Line ����� ����������� ������ �����.
/// @param B Line ����� ����������� ������ �����.
/// @return bool
bool crossP(Line A, Line B);
/// @brief ������� ����������� ������������� ������� ����������� ���� �����.
/// @param A Line ����� ����������� ������ �����.
/// @param B Line ����� ����������� ������ �����.
/// @return bool
bool crossLn(Line A, Line B);
/// @brief ��������� ������������.
/// @param A Line ����� ����������� ������ �����.
/// @param B Line ����� ����������� ������ �����.
/// @return int ����� ��������.
int vecpro(Line A, Line B);
/// @brief ������� ��������� ����� ����������� ���� ������.
/// @param A Line ����� ����������� ������ �����.
/// @param B Line ����� ����������� ������ �����.
/// @return CPoint ����� ����������� ������ �����.
CPoint CrossPoint(Line A, Line B);
/// @brief ������� ��������� ������� ����������� ���� ������.
/// @param A Line ����� ����������� ������ �����.
/// @param B Line ����� ����������� ������ �����.
/// @return Line ����� ����������� ������ �����.
Line CrossLine(Line A, Line B);
/// @brief ������� ����������� ������� �������� �� ����������� ���������.
/// @param points ������ ������ ��������.
void check1(std::vector<CPoint> points);
/// @brief ������� ����������� ������� �������� �� ����������� ���������.
/// @param lines ������ ������ ��������.
void check2(std::vector<Line> lines);
/// class Poligon
/// @brief ����� ����������� ������ �������.
class Poligon {
public:
    /// @brief ������ ���������� ��������� ����� ��������.
    std::vector<CPoint> points;
    /// @brief ������ ���������� ��������� ����� ��������.
    std::vector<Line> lines;
    /// @brief ����������� �������� �� ���������.
    Poligon() = default;
    /// @brief ���������� �������� �� ���������.
    ~Poligon() = default;
    /// @brief ����������� �����.
    /// @param P ��������� ������ Poligon.
    Poligon(const Poligon& P);
    /// @brief ����������� ����������� ������ ������ ��������.
    /// @param cpoints ������ ���������� ��������� ����� ��������.
    Poligon(std::vector<CPoint> cpoints);
    /// @brief ����������� ����������� ������ ������ ��������.
    /// @param cpoints ������ ���������� ��������� ����� cv::Point �������� .
    Poligon(std::vector<cv::Point> cpoints);
    /// @brief ������� ��� ��������� ������ ��������.
    /// @param imeg cv::Mat n-������ ����� ������� ��������.
    /// @param color cv::Scalar ����� �������� ��� 4-����������� �������, ������������ �� Vec.
    void DrawPoints(cv::Mat imeg, cv::Scalar color);
    /// @brief ������� ��� ��������� ����� ��������.
    /// @param imeg cv::Mat n-������ ����� ������� ��������.
    /// @param color cv::Scalar ����� �������� ��� 4-����������� �������, ������������ �� Vec.
    void DrawLines(cv::Mat imeg, cv::Scalar color);
    /// @brief ������� ��� ��������� ��������.
    /// @param imeg cv::Mat n-������ ����� ������� ��������.
    /// @param color cv::Scalar ����� �������� ��� 4-����������� �������, ������������ �� Vec.
    void DrawPoligon(cv::Mat imeg, cv::Scalar color);
    /// @brief ������� ��� ������ ��������.
    /// @param ostrm �������� �����.
    /// @return std::ostream �������� �����.
    std::ostream& writeTo(std::ostream& ostrm) const;
    /// @brief ������� ��� ������ ��������.
    /// @param istrm ������� �����.
    /// @return std::istream ������� �����.
    std::istream& readFrom(std::istream& istrm);
};
/// @brief ������� ����������� ��������� �� ����� ������ ��������.
/// @param P class Poligon ������� ��� �������� �������� ��������.
/// @param a class CPoint ����� ������� �������� ��������.
/// @return bool
bool Interpoint(const Poligon P, const CPoint a);
/// @brief ������� ��� ���������� ����� �������
/// @param l class Line ����� ����������� ������ �����.
/// @return double ����� �������
double veclen(Line l);
/// @brief ������� ��� ���������� �������� ���� ����� ����� �������
/// @param l1 class Line ����� ����������� ������ �����.
/// @param l2 class Line ����� ����������� ������ �����.
/// @return double ������� ���� ����� ���������.
double angle(Line l1, Line l2);
/// @brief ������� ��� ���������� �����. 
/// ��������� ����� �� ����������� ���� ����� �������������� �������� ����������� �� ������� 
/// � ���������� ����������� y � ��������� ������������� �������� � ���������� ����������� y � ���������� ��������� ��������.
/// @param points ������ ���������� ��������� ����� ��������.
void sortPoint(std::vector<CPoint>& points);
/// @brief ������� ��� ���������� �������� ����������� ���� ���������.
/// @param A �������.
/// @param B �������.
/// @return ������� �����������.
Poligon Interseption(Poligon A, Poligon B);
#endif
