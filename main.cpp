#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QStackedWidget>
#include <QTextEdit>
#include <QFileDialog>
#include <QFile>

// Fonction pour créer la barre de menu
void createMenuBar(QMenuBar &menuBar, QStackedWidget &stackedWidget) {
    QMenu *fileMenu = menuBar.addMenu("File");

    QAction *openAction = fileMenu->addAction("Open");
    QObject::connect(openAction, &QAction::triggered, [&stackedWidget]() {
        QString filePath = QFileDialog::getOpenFileName(nullptr, "Open File", QString(), "Text Files (*.txt);;All Files (*)");

        if (!filePath.isEmpty()) {
            QWidget *page = new QWidget;
            QVBoxLayout *layout = new QVBoxLayout(page);
            QTextEdit *textEdit = new QTextEdit(page);

            QFile file(filePath);
            if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QTextStream in(&file);
                textEdit->setPlainText(in.readAll());
                file.close();

                layout->addWidget(textEdit);
                stackedWidget.addWidget(page);
                stackedWidget.setCurrentWidget(page);
            }
        }
    });

    QAction *saveAction = fileMenu->addAction("Save");
    // Connecter saveAction à une fonction pour sauvegarder le contenu, si nécessaire

    QAction *exitAction = fileMenu->addAction("Exit");
    // Connecter exitAction à une fonction pour quitter l'application, si nécessaire

    QMenu *optionsMenu = menuBar.addMenu("Options");

    // Add "Option 1" action
    QAction *option1Action = optionsMenu->addAction("Option 1");
    option1Action->setObjectName("option1Action");
    QObject::connect(option1Action, &QAction::triggered, [&stackedWidget]() {
        // Handling for "Option 1" action
        // ...
    });

    // Add "Option 2" action
    QAction *option2Action = optionsMenu->addAction("Option 2");
    option2Action->setObjectName("option2Action");
    QObject::connect(option2Action, &QAction::triggered, [&stackedWidget]() {
        // Handling for "Option 2" action
        // ...
    });

    // Create "Help" menu
    QMenu *helpMenu = menuBar.addMenu("Help");

    // Add "About" action
    QAction *aboutAction = helpMenu->addAction("About");
    aboutAction->setObjectName("aboutAction");
    QObject::connect(aboutAction, &QAction::triggered, [&stackedWidget]() {
        // Handling for "About" action
        // ...
    });
}



// Fonction pour créer le layout des boutons supérieurs
void createTopButtonsLayout(QHBoxLayout &topButtonsLayout, QStackedWidget &stackedWidget) {
    QPushButton *buttons[5];

    for (int i = 0; i < 5; ++i) {
        buttons[i] = new QPushButton("Button " + QString::number(i + 1));
        topButtonsLayout.addWidget(buttons[i]);

        QObject::connect(buttons[i], &QPushButton::clicked, [&stackedWidget, i]() {
            stackedWidget.setCurrentIndex(i);
        });
    }
}


// Fonction pour créer une page avec QTextEdit et un bouton "Send" uniquement pour le bouton 1
void createTextEditPage(QStackedWidget &stackedWidget, const QString &pageTitle, int buttonIndex) {
    QWidget *page = new QWidget;
    QVBoxLayout *pageLayout = new QVBoxLayout(page);

    if (buttonIndex == 0) {
        QLabel *labelQuestion = new QLabel("Question:", page);
        QTextEdit *textEditQuestion = new QTextEdit(page);
        textEditQuestion->setStyleSheet("margin-bottom: 5px;");

        QLabel *labelAnswer = new QLabel("Answer:", page);
        QTextEdit *textEditAnswer = new QTextEdit(page);
        textEditAnswer->setStyleSheet("margin-bottom: 5px;");

        QPushButton *sendButton = new QPushButton("Send", page);

        pageLayout->addWidget(labelQuestion);
        pageLayout->addWidget(textEditQuestion);
        pageLayout->addWidget(labelAnswer);
        pageLayout->addWidget(textEditAnswer);
        pageLayout->addWidget(sendButton);
        pageLayout->setSpacing(5);

        // Connect the button click signal to a slot for handling
        QObject::connect(sendButton, &QPushButton::clicked, [textEditQuestion, textEditAnswer]() {
            // Handle the "Send" button click event
            qDebug() << "Send button clicked!";
            qDebug() << "Question: " << textEditQuestion->toPlainText();
            qDebug() << "Answer: " << textEditAnswer->toPlainText();
        });
    }else if (buttonIndex == 1) {
        // Page pour le bouton 2 (Mes Decks)
        QLabel *labelMesDecks = new QLabel("Mes Decks:", page);
        QTextEdit *textEditMesDecks = new QTextEdit(page);
        textEditMesDecks->setStyleSheet("margin-bottom: 5px;");
        textEditMesDecks->setPlainText("Liste de vos decks ici...");

        pageLayout->addWidget(labelMesDecks);
        pageLayout->addWidget(textEditMesDecks);
    } else if (buttonIndex == 2) {
        // Page pour le bouton 3 (Parcourir)
        QLabel *labelParcourir = new QLabel("Parcourir:", page);
        QTextEdit *textEditParcourir = new QTextEdit(page);
        textEditParcourir->setStyleSheet("margin-bottom: 5px;");
        textEditParcourir->setPlainText("Contenu du parcours ici...");

        pageLayout->addWidget(labelParcourir);
        pageLayout->addWidget(textEditParcourir);
    } else if (buttonIndex == 3) {
        // Page pour le bouton 4 (Statistiques)
        QLabel *labelStatistiques = new QLabel("Statistiques:", page);
        QTextEdit *textEditStatistiques = new QTextEdit(page);
        textEditStatistiques->setStyleSheet("margin-bottom: 5px;");
        textEditStatistiques->setPlainText("Statistiques ici...");

        pageLayout->addWidget(labelStatistiques);
        pageLayout->addWidget(textEditStatistiques);
    } else if (buttonIndex == 4) {
        // Page pour le bouton 5 (Page sans contenu défini)
        QLabel *labelPlaceholder = new QLabel("Contenu à définir pour le bouton 5.", page);

        pageLayout->addWidget(labelPlaceholder);
    }

    stackedWidget.addWidget(page);
}




void goToHomePage(QStackedWidget &stackedWidget) {
    stackedWidget.setCurrentIndex(0); // Index 0 correspond à la page d'accueil
}


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Create the main window
    QWidget window;
    window.setWindowTitle("Ykna");

    // Create the layout
    QVBoxLayout layout;

    // Create a menu bar
    QMenuBar menuBar;
    QStackedWidget stackedWidget;

    // Create buttons and connect them to change the current page
    createMenuBar(menuBar, stackedWidget);

    qDebug() << "Number of actions in menuBar: " << menuBar.actions().size(); // Ajout de la ligne de débogage

    // Create the top buttons layout
    QHBoxLayout topButtonsLayout;

    // Create pages for each button
    for (int i = 1; i <= 5; ++i) {
        createTextEditPage(stackedWidget, "Page for Button " + QString::number(i), i - 1);
    }

    // Create buttons and connect them to change the current page
    createTopButtonsLayout(topButtonsLayout, stackedWidget);

    // Set the top buttons layout
    layout.addWidget(&menuBar);
    layout.addLayout(&topButtonsLayout);
    layout.addWidget(&stackedWidget);

    // Create the welcome label
    QLabel *welcomeLabel = new QLabel("Welcome to Ykna!");
    welcomeLabel->setAlignment(Qt::AlignCenter);
    stackedWidget.addWidget(welcomeLabel);

    // Set the layout
    window.setLayout(&layout);

    // Connect the menu actions to slots or functions for handling
    if (menuBar.actions().size() > 2) {
        QObject::connect(menuBar.actions().at(2), &QAction::triggered, &app, &QApplication::quit); // exitAction
    } else {
        qDebug() << "Exit action not found!";
    }

    // Show the window
    window.show();

    // Run the application
    return app.exec();
}


