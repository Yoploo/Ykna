#ifndef YKNA_FRONT_H
#define YKNA_FRONT_H

#include <QMenuBar>
#include <QHBoxLayout>
#include <QStackedWidget>
#include <QString>


void createMenuBar(QMenuBar &menuBar, QStackedWidget &stackedWidget);
void createTopButtonsLayout(QHBoxLayout &topButtonsLayout, QStackedWidget &stackedWidget);
void createTextEditPage(QStackedWidget &stackedWidget, const QString &pageTitle, int buttonIndex);
void goToHomePage(QStackedWidget &stackedWidget);
void createLoginPage(QStackedWidget &stackedWidget);
void createRegisterPage(QStackedWidget &stackedWidget);

#endif //YKNA_FRONT_H
