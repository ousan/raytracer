#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "raytracer.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

Raytracer raytracer;

QStringList getListFromText(const QString s)
{
    QRegExp rx("(\\ |\\,|\\:|\\t)");
    QStringList list = s.split(rx);
    return list;
}

static Vector3 getVectorFromText(const QString s)
{
    Vector3 v;
    QStringList list = getListFromText(s);
    if(list.size() == 1)
    {
        return Vector3(0,0,0);
    }
    qDebug("list %s %s %s", list.at(0).toStdString().c_str(),list.at(1).toStdString().c_str(),list.at(2).toStdString().c_str());
    v=Vector3(list.at(0).toInt(),list.at(1).toInt(),list.at(2).toInt());
    return v;
}

static Color getColorFromText(const QString s)
{
    Color c;

    QStringList list = getListFromText(s);
    if(list.size() == 1)
    {
        return Color(0,0,0);
    }
    qDebug("list %s %s %s", list.at(0).toStdString().c_str(),list.at(1).toStdString().c_str(),list.at(2).toStdString().c_str());

    c=Color(list.at(0).toInt(),list.at(1).toInt(),list.at(2).toInt());
    return c;
}

static void setCamera(Ui::MainWindow *ui)
{
    /*Setting Camera Position*/
    QString c_position = ui->cameraPositionLineEdit->text();
    QString fov = ui->cameraFovLineEdit->text();
    //qDebug("c_position %s fov  %s",c_position.toStdString().c_str(),fov.toStdString().c_str() );
    Vector3 v_c_position = getVectorFromText(c_position);
    float f_fov =fov.toFloat();

    raytracer.setCameraPosition(v_c_position, f_fov);
}

static void setCanvas(Ui::MainWindow *ui)
{
    /*Setting canvas size*/
    QString inputHeight = ui->canvasHeightLineEdit->text();
    QString inputWidth = ui->canvasWidthLineEdit->text();
    int height = inputHeight.toInt();
    int width = inputWidth.toInt();
    //qDebug("inputWidth %d inputHeight %d",width,height);

    raytracer.setCanvasSize(width, height);
}

static void setLight(Ui::MainWindow *ui)
{
    /*Addingscene light with intensity*/
    QString l_position = ui->lightPositionLineEdit->text();
    QString l_intensity = ui->lightIntensityLineEdit->text();
    //qDebug("l_position %s l_intensity  %s",l_position.toStdString().c_str(),l_intensity.toStdString().c_str() );
    Vector3 v_l_position = getVectorFromText(l_position);
    Vector3 v_l_intensity = getVectorFromText(l_intensity);

    raytracer.addSceneLight(v_l_position, v_l_intensity);
}

void MainWindow::on_renderButton_clicked()
{
    ui->renderButton->setEnabled(false);
    setCamera(ui);
    setCanvas(ui);
    setLight(ui);

    raytracer.renderScene();
    QMessageBox msgBox;
    msgBox.setText("Render Completed.");
    msgBox.exec();
    ui->renderButton->setEnabled(true);
}

void MainWindow::on_addSpherePushButton_clicked()
{
    QString s_position = ui->spherePositionLineEdit->text();
    QString s_radius = ui->sphereRadiusLineEdit->text();
    QString s_color = ui->sphereColorLineEdit->text();

    Vector3 vector_position = getVectorFromText(s_position);
    int radius = s_radius.toInt();
    Color color = getColorFromText(s_color);

    //qDebug("s_position %s s_radius  %s s_color %s",s_position.toStdString().c_str(),s_radius.toStdString().c_str(), s_color.toStdString().c_str() );
    raytracer.addSphere(vector_position, radius, color);
    QMessageBox msgBox;
    msgBox.setText("Sphere is added.");
    msgBox.exec();
}

void MainWindow::on_addTrianglePushButton_clicked()
{
    QString t_positionA = ui->trianglePosALineEdit->text();
    QString t_positionB = ui->trianglePosBLineEdit->text();
    QString t_positionC = ui->trianglePosCLineEdit->text();
    QString t_color = ui->triangleColorLineEdit->text();

    Vector3 vectorA = getVectorFromText(t_positionA);
    Vector3 vectorB = getVectorFromText(t_positionB);
    Vector3 vectorC = getVectorFromText(t_positionC);
    Color color = getColorFromText(t_color);


    raytracer.addTriangle(vectorA,vectorB,vectorC,color);
    QMessageBox msgBox;
    msgBox.setText("Triangle is added.");
    msgBox.exec();
    //qDebug("t_positionA %s, t_positionB %s, t_positionC %s, t_color %s",t_positionA.toStdString().c_str(),t_positionB.toStdString().c_str(),t_positionC.toStdString().c_str(),t_color.toStdString().c_str());
    //raytracer.addTriangle( Vector3(0, 4, -30), Vector3(5, -4, -30), Vector3(-5, -4, -30), Color(165, 10, 14));
}
