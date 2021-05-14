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
    Color(cv::Scalar &color)
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
 

///@brief ������� ��� ������ �����.
/// @param ostrm �������� �����.
/// @return std::ostream �������� �����.
std::ostream& writeTo(std::ostream& ostrm, const cv::Point2d &A);
/// @brief ������� ��� ������ �����.
/// @param istrm ������� �����.
/// @return std::istream ������� �����.
std::istream& readFrom(std::istream& istrm, cv::Point2d& A);
/// @brief ����� ����������� ������� ����� � �������.
/// @param p ����� ������� ������ � �������.
/// @param points ������ � ������� ��������� �����.
/// @return bool
bool compP(const cv::Point2d &p, const std::vector<cv::Point2d> &points);
/// @class Line
/// @brief ����� ����������� ������ �����.
class Edge {
public:
    /// @brief ����� A ������� �������.
    cv::Point2d A{ -1,-1 };
    /// @brief ����� B ������� �������.
    cv::Point2d B{ -1,-1 };
    /// @brief ������� �����.
    int thickness{ -1 };
    /// @brief ��� �����.
    int linetype{ 8 };
    /// @brief ���������� ������� ����� � ����������� �����.
    int shift{ 0 };
    /// @brief ����������� ����� �� ���������.
    Edge() = default;
    /// @brief ���������� ����� �� ���������.
    ~Edge() = default;
    /// @brief ����������� ����������� ������� �������.
    /// @param A ������� �������.
    /// @param B ������� �������.
    Edge(const cv::Point2d &A,const cv::Point2d &B);
    /// @brief ����������� ����������� ������� �������.
    /// @param A ������� �������.
    /// @param B ������� �������.
    /// @param thickness ������� �����.
    Edge(const cv::Point2d &A,const cv::Point2d &B, int thickness);
    /// @brief ����������� ����������� ������� �������.
    /// @param A ������� �������.
    /// @param B ������� �������.
    /// @param thickness ������� �����.
    /// @param linetype ��� �����.
    Edge(const cv::Point2d &A,const cv::Point2d &B, int thickness, int linetype);
    /// @brief ����������� ����������� ������� �������.
    /// @param A ������� �������.
    /// @param B ������� �������.
    /// @param thickness ������� �����.
    /// @param linetype ��� �����.
    /// @param shift ���������� ������� ����� � ����������� �����.
    Edge(const cv::Point2d &A,const cv::Point2d &B, int thickness, int linetype, int shift);
    /// @brief ����������� �����.
    /// @param A ������ class Line.
    Edge(const Edge& A);
    /// @brief ������� ��� ��������� �����.
    /// @param imeg cv::Mat n-������ ����� ������� ��������.
    void DrawLine(cv::Mat &imeg);
    /// @brief ������� ��� ��������� �����.
    /// @param imeg cv::Mat n-������ ����� ������� ��������.
    /// @param color cv::Scalar ����� �������� ��� 4-����������� �������, ������������ �� Vec.
    void DrawLine(cv::Mat &imeg, cv::Scalar color);
    /// @brief ����� ��� ���������� ����� �����.
    /// @return ����� �������� ����� �����.
    double Lenght() const;
};

/// @brief ������� ����������� ������������� ����� ����������� ���� �����.
/// @param A Line ����� ����������� ������ �����.
/// @param B Line ����� ����������� ������ �����.
/// @return bool
bool crossP(const Edge &A, const Edge &B);
/// @brief ������� ����������� ������������� ������� ����������� ���� �����.
/// @param A Line ����� ����������� ������ �����.
/// @param B Line ����� ����������� ������ �����.
/// @return bool
bool crossLn(const Edge &A, const Edge &B);
/// @brief ��������� ������������.
/// @param A Line ����� ����������� ������ �����.
/// @param B Line ����� ����������� ������ �����.
/// @return int ����� ��������.
double vecpro(const Edge &A,const Edge &B);
/// @brief ������� ��������� ����� ����������� ���� ������.
/// @param A Line ����� ����������� ������ �����.
/// @param B Line ����� ����������� ������ �����.
/// @return CPoint ����� ����������� ������ �����.
cv::Point2d CrossPoint(const Edge &A,const Edge &B);
/// @brief ������� ��������� ������� ����������� ���� ������.
/// @param A Line ����� ����������� ������ �����.
/// @param B Line ����� ����������� ������ �����.
/// @return Line ����� ����������� ������ �����.
Edge CrossLine(const Edge &A, const Edge &B);
/// @brief ������� ����������� ������� �������� �� ����������� ���������.
/// @param points ������ ������ ��������.
void check1(const std::vector<cv::Point2d> &points);
/// @brief ������� ����������� ������� �������� �� ����������� ���������.
/// @param lines ������ ������ ��������.
void check2(const std::vector<Edge> &lines);
/// class Poligon
/// @brief ����� ����������� ������ �������.
class Poligon {
public:
    /// @brief ������ ���������� ��������� ����� ��������.
    std::vector<cv::Point2d> points{};
    /// @brief ������ ���������� ��������� ����� ��������.
    std::vector<Edge> lines{};
    /// @brief ����������� �������� �� ���������.
    Poligon() = default;
    /// @brief ���������� �������� �� ���������.
    ~Poligon() = default;
    /// @brief ����������� �����.
    /// @param P ��������� ������ Poligon.
    Poligon(const Poligon& P);
    /// @brief ����������� ����������� ������ ������ ��������.
    /// @param cpoints ������ ���������� ��������� ����� cv::Point �������� .
    Poligon(const std::vector<cv::Point2d>& cpoints);
    /// @brief ������� ��� ��������� ������ ��������.
    /// @param imeg cv::Mat n-������ ����� ������� ��������.
    /// @param color cv::Scalar ����� �������� ��� 4-����������� �������, ������������ �� Vec.
    void DrawPoints(cv::Mat &imeg, cv::Scalar color);
    /// @brief ������� ��� ��������� ����� ��������.
    /// @param imeg cv::Mat n-������ ����� ������� ��������.
    /// @param color cv::Scalar ����� �������� ��� 4-����������� �������, ������������ �� Vec.
    void DrawLines(cv::Mat &imeg, cv::Scalar color);
    /// @brief ������� ��� ��������� ��������.
    /// @param imeg cv::Mat n-������ ����� ������� ��������.
    /// @param color cv::Scalar ����� �������� ��� 4-����������� �������, ������������ �� Vec.
    void DrawPoligon(cv::Mat &imeg, cv::Scalar color);
    /// @brief ������� ��� ������ ��������.
    /// @param ostrm �������� �����.
    /// @return std::ostream �������� �����.
    std::ostream& write(std::ostream& ostrm) const;
    /// @brief ������� ��� ������ ��������.
    /// @param istrm ������� �����.
    /// @return std::istream ������� �����.
    std::istream& read(std::istream& istrm);
};
/// @brief ������� ����������� ��������� �� ����� ������ ��������.
/// @param P class Poligon ������� ��� �������� �������� ��������.
/// @param a class CPoint ����� ������� �������� ��������.
/// @return bool
bool Interpoint(const Poligon &P, const cv::Point2d &a);
/// @brief ������� ��� ���������� ����� �������
/// @param l class Line ����� ����������� ������ �����.
/// @return double ����� �������
double veclen(const Edge &l);
/// @brief ������� ��� ���������� �������� ���� ����� ����� �������
/// @param l1 class Line ����� ����������� ������ �����.
/// @param l2 class Line ����� ����������� ������ �����.
/// @return double ������� ���� ����� ���������.
double angle(const Edge &l1,const Edge &l2);
/// @brief ������� ��� ���������� �����. 
/// ��������� ����� �� ����������� ���� ����� �������������� �������� ����������� �� ������� 
/// � ���������� ����������� y � ��������� ������������� �������� � ���������� ����������� y � ���������� ��������� ��������.
/// @param points ������ ���������� ��������� ����� ��������.
void sortPoint(std::vector<cv::Point2d>& points);
/// @brief ������� ��� ���������� �������� ����������� ���� ���������.
/// @param A �������.
/// @param B �������.
/// @return ������� �����������.
Poligon Interseption(const Poligon &A, const Poligon &B);
#endif
