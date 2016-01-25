/*
 * Subsection.h
 *
 *  Created on: 19.04.2015
 *      Author: alex
 */

#ifndef BGL_SUBSECTION_H_
#define BGL_SUBSECTION_H_

#include "fs/bgl/bglbase.h"

namespace atools {
namespace io {
class BinaryStream;
}
}

namespace atools {
namespace fs {
namespace bgl {

class Section;

class Subsection :
  public atools::fs::bgl::BglBase
{
public:
  Subsection(atools::io::BinaryStream *bs, const Section& parentSect);
  virtual ~Subsection();

  int getDataSize() const
  {
    return dataSize;
  }

  int getFirstDataRecordOffset() const
  {
    return firstDataRecordOffset;
  }

  int getId() const
  {
    return id;
  }

  int getNumDataRecords() const
  {
    return numDataRecords;
  }

  const Section& getParent() const
  {
    return *parent;
  }

private:
  friend QDebug operator<<(QDebug out, const atools::fs::bgl::Subsection& section);

  int id, numDataRecords, firstDataRecordOffset, dataSize;
  const atools::fs::bgl::Section *parent;
};

} // namespace bgl
} // namespace fs
} // namespace atools

#endif /* BGL_SUBSECTION_H_ */