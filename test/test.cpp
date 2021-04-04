#include <poligon.h>
#include<fstream>
int main() {
    cv::Mat imeg = cv::Mat::zeros(cv::Size(800, 600), CV_8UC3);
    cv::namedWindow("image", cv::WINDOW_NORMAL);
    //Создаем два полигона
    Poligon POl(std::vector<CPoint> {CPoint(250, 500), CPoint(500, 300), CPoint(200, 300)});
    POl.DrawPoligon(imeg, Blue.color);
    Poligon P(std::vector<CPoint> {CPoint(150, 300), CPoint(250, 200), CPoint(550, 250), CPoint(300, 500)});
    P.DrawPoligon(imeg, cv::Scalar(0, 255, 0));
    //Находим пересечение
    Poligon res = Interseption(POl, P);
    res.DrawPoligon(imeg, Red.color);
    cv::imshow("image", imeg);
    cv::waitKey(0);
}