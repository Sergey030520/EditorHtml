#include <QApplication>
#include <QMainWindow>
#include <QWebEngineView>
#include <QHBoxLayout>
#include <QPlainTextEdit>
#include <QLineEdit>
#include <iostream>



int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    auto* editorWebWin = new QWidget();
    auto* hbox = new QHBoxLayout(editorWebWin);

    QPlainTextEdit htmlEdit;
    QWebEngineView webView(editorWebWin);

    webView.setMinimumSize(editorWebWin->width() / 2, editorWebWin->height() / 2);
    htmlEdit.setMinimumSize(editorWebWin->width() / 2, editorWebWin->height() / 2);

    hbox->addWidget(&htmlEdit);
    hbox->addWidget(&webView);

    QObject::connect(&htmlEdit, &QPlainTextEdit::textChanged, [ &htmlEdit, &webView](){
        webView.setHtml(htmlEdit.toPlainText());
    });

    editorWebWin->resize(400, 500);
    editorWebWin->show();
    return QApplication::exec();
}

#include "main.moc"