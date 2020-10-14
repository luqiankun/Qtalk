#include <QCoreApplication>
#include <QObject>
#include <iostream>
//≤‚ ‘
#include "serversocket.h"
#include "sql.h"
//
int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);
  ServerSocket server;
  return a.exec();
}
