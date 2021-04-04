/// @file poligon.cpp
/// @brief Файл реализации библиотеки.
#include"poligon.h"

CPoint::CPoint(int x, int y)
    :x(x), y(y) {}
CPoint::CPoint(const CPoint& a)
    : x(a.x), y(a.y) {}
CPoint::CPoint(const cv::Point& a)
    : x(a.x), y(a.y) {}
void CPoint::DrawPoint(cv::Mat imeg)
{
    circle(imeg, cv::Point(x, y), 3, cv::Scalar(255, 255, 255), -1, 8);
}
void CPoint::DrawPoint(cv::Mat imeg, cv::Scalar color)
{
    circle(imeg, cv::Point(x, y), 3, color, -1, 8);
}
const bool CPoint::operator == (const CPoint p)
{
    if (this->x == p.x && this->y == p.y)
        return true;
    else return false;
}
const bool CPoint::operator!=(const CPoint p)
{
    if (this->x == p.x && this->y == p.y)
        return false;
    else return true;
}
std::ostream& CPoint::writeTo(std::ostream& ostrm) const
{
    ostrm << x << " " << y;
    return ostrm;
}

std::istream& CPoint::readFrom(std::istream& istrm)
{
    int xin(0);
    int yin(0);
    istrm >> xin >> yin;
    if (istrm.good())
    {
        x = xin;
        y = yin;
    }
    return istrm;
}


bool compP(CPoint p, std::vector<CPoint> points)
{
    bool res = false;
    for (int i = 0; i < points.size(); i++)
    {
        if (p == points[i])
            res = true;
    }
    return res;
}


Line::Line(CPoint A, CPoint B)
    :A(A), B(B) {}
Line::Line(CPoint A, CPoint B, int thickness)
    : A(A), B(B), thickness(thickness) {}
Line::Line(CPoint A, CPoint B, int thickness, int linetype)
    : A(A), B(B), thickness(thickness), linetype(linetype) {}
Line::Line(CPoint A, CPoint B, int thickness, int linetype, int shift)
    : A(A), B(B), thickness(thickness), linetype(linetype), shift(shift) {}
Line::Line(const Line& A)
    : A(A.A), B(A.B) {}
void Line::DrawLine(cv::Mat imeg)
{
    line(imeg, cv::Point(A.x, A.y), cv::Point(B.x, B.y), cv::Scalar(255, 255, 255), thickness, linetype, shift);
}
void Line::DrawLine(cv::Mat imeg, cv::Scalar color)
{
    line(imeg, cv::Point(A.x, A.y), cv::Point(B.x, B.y), color, thickness, linetype, shift);
}
int Line::Lenght()
{
    CPoint a(A);
    CPoint b(B);
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}


bool crossP(Line A, Line B)
{
    CPoint a(A.A);
    CPoint b(A.B);
    CPoint c(B.A);
    CPoint d(B.B);
    double x1(a.x), y1(a.y), x2(b.x), y2(b.y), x3(c.x), y3(c.y), x4(d.x), y4(d.y);
    double Ua, Ub, numerator_a, numerator_b, denominator;
    denominator = (y4 - y3) * (x1 - x2) - (x4 - x3) * (y1 - y2);
    if (denominator == 0) {
        if ((x1 * y2 - x2 * y1) * (x4 - x3) - (x3 * y4 - x4 * y3) * (x2 - x1) == 0 && (x1 * y2 - x2 * y1) * (y4 - y3) - (x3 * y4 - x4 * y3) * (y2 - y1) == 0)
            return false;
        else return false;
    }
    else {
        numerator_a = (x4 - x2) * (y4 - y3) - (x4 - x3) * (y4 - y2);
        numerator_b = (x1 - x2) * (y4 - y2) - (x4 - x2) * (y1 - y2);
        Ua = numerator_a / denominator;
        Ub = numerator_b / denominator;
        return (Ua >= 0 && Ua <= 1 && Ub >= 0 && Ub <= 1 ? true : false);
    }
}

bool crossLn(Line A, Line B)
{
    CPoint a(A.A);
    CPoint b(A.B);
    CPoint c(B.A);
    CPoint d(B.B);
    double x1(a.x), y1(a.y), x2(b.x), y2(b.y), x3(c.x), y3(c.y), x4(d.x), y4(d.y);
    double Ua, Ub, numerator_a, numerator_b, denominator;
    denominator = (y4 - y3) * (x1 - x2) - (x4 - x3) * (y1 - y2);
    if (denominator == 0) {
        if ((x1 * y2 - x2 * y1) * (x4 - x3) - (x3 * y4 - x4 * y3) * (x2 - x1) == 0 && (x1 * y2 - x2 * y1) * (y4 - y3) - (x3 * y4 - x4 * y3) * (y2 - y1) == 0)
            return true;
        else return false;
    }
    else {
        numerator_a = (x4 - x2) * (y4 - y3) - (x4 - x3) * (y4 - y2);
        numerator_b = (x1 - x2) * (y4 - y2) - (x4 - x2) * (y1 - y2);
        Ua = numerator_a / denominator;
        Ub = numerator_b / denominator;
        return (Ua >= 0 && Ua <= 1 && Ub >= 0 && Ub <= 1 ? false : false);
    }
}
int vecpro(Line A, Line B)
{
    int x1(A.B.x - A.A.x);
    int y1(A.B.y - A.A.y);
    int x2(B.B.x - B.A.x);
    int y2(B.B.y - B.A.y);
    return x1 * y2 - y1 * x2;
}

CPoint CrossPoint(Line A, Line B)
{
    int det, x1, y1, x2, y2, x3, y3, x4, y4, a1, a2, b1, b2, c1, c2;
    CPoint T;
    CPoint a(A.A);
    CPoint b(A.B);
    CPoint c(B.A);
    CPoint d(B.B);
    x1 = A.A.x;
    y1 = A.A.y;
    x2 = A.B.x;
    y2 = A.B.y;
    x3 = B.A.x;
    y3 = B.A.y;
    x4 = B.B.x;
    y4 = B.B.y;
    a1 = y1 - y2;
    b1 = x2 - x1;
    c1 = x1 * y2 - x2 * y1;
    a2 = y3 - y4;
    b2 = x4 - x3;
    c2 = x3 * y4 - x4 * y3;
    det = a1 * b2 - a2 * b1;
    if (det != 0)
    {
        T.x = (b1 * c2 - b2 * c1) / det;
        T.y = (a2 * c1 - a1 * c2) / det;
    }
    return T;
}
Line CrossLine(Line A, Line B)
{
    CPoint a(A.A);
    CPoint b(A.B);
    CPoint c(B.A);
    CPoint d(B.B);

    int ALenght(A.Lenght());
    int BLenght(B.Lenght());
    return (ALenght < BLenght ? A : B);
}


void check1(std::vector<CPoint> points)
{
    if (points.size() < 3)
    {
        std::cout << "The polygon contains at least 3 vertices.";
        exit(2);
    }
    for (size_t i = 0; i < points.size(); i++)
    {
        for (size_t j = 0; j < points.size(); j++)
        {
            if (points[i] == points[j] && i != j)
            {
                std::cout << "No point is a vertex (on the same polygon) more than once.";
                exit(2);
            }
        }
    }

}
void check2(std::vector<Line> lines)
{

    int pos{ 0 };
    int neg{ 0 };
    int zeros{ 0 };
    for (size_t i = 0; i < lines.size() - 1; i++)
    {
        if (vecpro(lines[i], lines[i + 1]) > 0)
        {
            pos += 1;
        }
        if (vecpro(lines[i], lines[i + 1]) < 0)
        {
            neg += 1;

        }
        if (vecpro(lines[i], lines[i + 1]) == 0)
        {
            zeros += 1;

        }
    }
    if (!((neg == 0 || pos == 0) && zeros == 0))
    {
        std::cout << "The polygon is non-convex.";
        exit(2);
    }
}
Poligon::Poligon(const Poligon& P)
    :points(P.points), lines(P.lines)
{
    check1(points);
    check2(lines);
}

Poligon::Poligon(std::vector<CPoint> cpoints)
{
    check1(cpoints);
    points = cpoints;
    for (std::ptrdiff_t i = 0; i < cpoints.size() - 1; ++i)
    {
        Line newline(cpoints[i], cpoints[i + 1]);
        lines.push_back(newline);
    }
    Line newline(cpoints[cpoints.size() - 1], cpoints[0]);
    lines.push_back(newline);
    check2(lines);
}


Poligon::Poligon(std::vector<cv::Point> cpoints)
{
    points.clear();
    for (size_t i = 0; i < cpoints.size(); i++)
    {
        CPoint tmp = cpoints[i];
        points.push_back(tmp);
    }
    check1(points);
    for (std::ptrdiff_t i = 0; i < cpoints.size() - 1; ++i)
    {
        Line newline(cpoints[i], cpoints[i + 1]);
        lines.push_back(newline);
    }
    Line newline(cpoints[cpoints.size() - 1], cpoints[0]);
    lines.push_back(newline);
    check2(lines);
}


void Poligon::DrawPoints(cv::Mat imeg, cv::Scalar color)
{
    for (std::ptrdiff_t i = 0; i < points.size(); ++i)
    {
        circle(imeg, cv::Point(points[i].x, points[i].y), 3, color, -1, 8);
    }
}
void Poligon::DrawLines(cv::Mat imeg, cv::Scalar color)
{
    for (int i = 0; i < lines.size(); ++i)
    {
        line(imeg, cv::Point(lines[i].A.x, lines[i].A.y), cv::Point(lines[i].B.x, lines[i].B.y), color, 2, 8, 0);
    }
    line(imeg, cv::Point(lines[0].A.x, lines[0].A.y), cv::Point(lines[lines.size() - 1].B.x, lines[lines.size() - 1].B.y), color, 2, 8, 0);
}

void Poligon::DrawPoligon(cv::Mat imeg, cv::Scalar color)
{
    DrawPoints(imeg, color);
    DrawLines(imeg, color);
}

std::ostream& Poligon::writeTo(std::ostream& ostrm) const
{
    for (size_t i = 0; i < points.size(); i++)
    {
        points[i].writeTo(ostrm);
        ostrm << std::endl;
    }
    return ostrm;
}

std::istream& Poligon::readFrom(std::istream& istrm)
{
    CPoint p;
    points.clear();
    while (p.readFrom(istrm))
    {
        this->points.push_back(p);
    }
    Poligon tmp(this->points);
    *this = tmp;
    return istrm;
}



bool Interpoint(const Poligon P, const CPoint a)
{
    int pos{ 0 };
    int neg{ 0 };
    int zeros{ 0 };
    for (size_t i = 0; i < P.lines.size(); i++)
    {
        Line newline(P.lines[i].A, a);
        if (vecpro(P.lines[i], newline) > 0)
        {
            pos += 1;


        }
        if (vecpro(P.lines[i], newline) < 0)
        {
            neg += 1;

        }
        if (vecpro(P.lines[i], newline) == 0)
        {
            zeros += 1;

        }
    }
    if ((neg == 0 || pos == 0) && zeros == 0) return true;
    else return false;
}
double veclen(Line l)
{
    double ax = l.B.x - l.A.x;
    double ay = l.B.y - l.A.y;
    return sqrt(ax * ax + ay * ay);
}


double angle(Line l1, Line l2)
{
    double res;
    double ax = l1.B.x - l1.A.x;
    double bx = l2.B.x - l2.A.x;
    double ay = l1.B.y - l1.A.y;
    double by = l2.B.y - l2.A.y;
    Line l3(l1.B, l2.B);
    double len1 = veclen(l1) * veclen(l1);
    double len2 = veclen(l2) * veclen(l2);
    double len3 = veclen(l3) * veclen(l3);
    res = (ax * bx + ay * by) / (sqrt(ax * ax + ay * ay) * sqrt(bx * bx + by * by));
    return res;
}


void sortPoint(std::vector<CPoint>& points)
{
    int min = points[0].y;
    int min_id = 0;
    for (size_t i = 0; i < points.size(); i++)
    {
        if (points[i].y < min)
        {
            min = points[i].y;
            min_id = i;
        }
    }
    int width = points[min_id].x;
    int height = min;
    int widthmat(width + 10);
    CPoint tmp = points[0];
    points[0] = points[min_id];
    points[min_id] = tmp;
    CPoint zero(width, height);
    CPoint direct(widthmat, height);
    Line abs(zero, direct);
    for (int j = 0; j < points.size() - 1; j++)
        for (int i = 0; i < points.size() - 1; i++)
        {
            Line l1(zero, points[i]);
            Line l2(zero, points[i + 1]);
            if ((angle(abs, l1) > angle(abs, l2)))
            {
                CPoint tmp = points[i];
                points[i] = points[i + 1];
                points[i + 1] = tmp;
            }
        }
}



Poligon Interseption(Poligon A, Poligon B) {
    std::vector<CPoint> points;
    std::vector<Line> lines;
    std::vector<std::vector<CPoint>> foundLinesA;
    std::vector<std::vector<CPoint>> foundLinesB;
    for (int i = 0; i < A.lines.size(); i++)
    {
        for (int j = 0; j < B.lines.size(); j++)
        {
            if (crossLn(A.lines[i], B.lines[j]) && !compP(CrossLine(A.lines[i], B.lines[j]).A, points) && !compP(CrossLine(A.lines[i], B.lines[j]).B, points))
            {
                points.push_back((CrossLine(A.lines[i], B.lines[j]).A));
                points.push_back((CrossLine(A.lines[i], B.lines[j]).B));
            }
            if (crossP(A.lines[i], B.lines[j]) && !compP(CrossPoint(A.lines[i], B.lines[j]), points))
            {
                points.push_back(CrossPoint(A.lines[i], B.lines[j]));
            }
        }
    }


    for (int j = 0; j < B.points.size(); j++)
    {

        if (Interpoint(A, B.points[j]) && !compP(B.points[j], points))
        {
            points.push_back(B.points[j]);
        }
    }


    for (int j = 0; j < A.points.size(); j++)
    {

        if (Interpoint(B, A.points[j]))
        {
            points.push_back(A.points[j]);
        }
    }
    sortPoint(points);
    Poligon inter(points);
    return inter;
};


