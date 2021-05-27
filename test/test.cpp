#include<poligon.h>
#include<fstream>
int main() {
    cv::Mat imeg = cv::Mat::zeros(cv::Size(800, 600), CV_8UC3);
    cv::namedWindow("image", cv::WINDOW_NORMAL);
    //Создаем два полигона
    Poligon test;
    Poligon POl(std::vector<cv::Point2d> {cv::Point2d(150.5, 300), cv:: Point2d(500, 300), cv::Point2d(500.67356, 500), cv::Point2d(250, 500)});
    test = POl;
    POl.DrawPoligon(imeg, Blue.color);
    Poligon P(std::vector<cv::Point2d> {cv::Point2d(150, 300), cv::Point2d(250, 200), cv::Point2d(550, 250), cv::Point2d(300.67878, 500.58763)});
    P.DrawPoligon(imeg, cv::Scalar(0, 255, 0));
    //Находим пересечение
    Poligon res = Interseption(test, P);
    res.DrawPoligon(imeg, Red.color);
    //Выводим в консоль координаты полигона пересечения
    res.write(std::cout);
    cv::imshow("image", imeg);
    cv::waitKey(0);
}