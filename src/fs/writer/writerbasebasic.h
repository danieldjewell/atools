/*
 * WriterBaseBasic.h
 *
 *  Created on: 01.06.2015
 *      Author: alex
 */

#ifndef WRITER_WRITERBASEBASIC_H_
#define WRITER_WRITERBASEBASIC_H_

#include "sql/sqlquery.h"

namespace atools {
namespace sql {
class SqlDatabase;
}

namespace fs {
class BglReaderOptions;
namespace writer {
class RunwayIndex;
class AirportIndex;
class DataWriter;

class WriterBaseBasic
{
public:
  WriterBaseBasic(atools::sql::SqlDatabase& sqlDb,
                  DataWriter& writer,
                  const QString& tablename,
                  const QString& sqlParam);

  virtual ~WriterBaseBasic();

protected:
  DataWriter& getDataWriter()
  {
    return dataWriter;
  }

  const BglReaderOptions& getOptions();

  RunwayIndex *getRunwayIndex();

  AirportIndex *getAirportIndex();

  atools::sql::SqlQuery& getStmt()
  {
    return stmt;
  }

  void bind(const QString& placeholder, const QVariant& val)
  {
    return stmt.bindValue(placeholder, val);
  }

  void executeStatement();
  void clearStatement();

private:
  atools::sql::SqlQuery stmt;
  QString sql, tablename;
  atools::sql::SqlDatabase& db;
  DataWriter& dataWriter;

};

} // namespace writer
} // namespace fs
} // namespace atools

#endif /* WRITER_WRITERBASEBASIC_H_ */
