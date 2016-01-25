/*****************************************************************************
* Copyright 2015-2016 Alexander Barthel albar965@mailbox.org
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*****************************************************************************/

#include "gui/errorhandler.h"
#include "logging/loggingdefs.h"

#include <QMessageBox>
#include <QApplication>
#include <QSqlError>
#include <QFileDevice>

namespace atools {

namespace gui {

void ErrorHandler::handleException(const std::exception& e, const QString& message)
{
  qCritical() << "Caught exception:" << e.what();

  QMessageBox::critical(parent, QApplication::applicationName(),
                        message + QString("\nCaught exception\n\"%1\"").arg(e.what()),
                        QMessageBox::Close, QMessageBox::NoButton);
}

void ErrorHandler::handleUnknownException(const QString& message)
{
  qCritical() << "Caught unknown exception";

  QMessageBox::critical(parent, QApplication::applicationName(),
                        message + QString("\nCaught unknown exception"),
                        QMessageBox::Close, QMessageBox::NoButton);

}

void ErrorHandler::handleSqlError(const QSqlError& error, const QString& message)
{
  qCritical() << "Sql error occured:" << error.text();

  QMessageBox::critical(parent, QApplication::applicationName(),
                        message + QString("\nSql error occured\n\"%1\"").arg(error.text()),
                        QMessageBox::Close, QMessageBox::NoButton);
}

void ErrorHandler::handleIOError(const QFileDevice& device, const QString& message)
{
  qCritical().nospace() << "IO error occured: " << device.errorString() << " (" << device.error() << ") "
                        << " file: " << device.fileName();

  QMessageBox::critical(parent, QApplication::applicationName(),
                        message + QString("\nIO error occured\nFile: \"%1\"\n\"%2\" (%3)").
                        arg(device.fileName()).arg(device.errorString()).arg(device.error()),
                        QMessageBox::Close, QMessageBox::NoButton);
}

} // namespace gui
} // namespace atools