/*
 * Localizer.cpp
 *
 *  Created on: 26.04.2015
 *      Author: alex
 */

#include "fs/bgl/nav/localizer.h"

#include "fs/bgl/recordtypes.h"
#include "io/binarystream.h"
#include "fs/bgl/converter.h"

namespace atools {
namespace fs {
namespace bgl {

using atools::io::BinaryStream;

Localizer::Localizer(BinaryStream *bs)
  : Record(bs)
{
  runwayNumber = bs->readByte();
  runwayDesignator = bs->readByte();
  heading = bs->readFloat();
  width = bs->readFloat();
}

Localizer::~Localizer()
{
}

QString Localizer::getRunwayName() const
{
  return converter::runwayToStr(runwayNumber, runwayDesignator);
}

QDebug operator<<(QDebug out, const Localizer& record)
{
  QDebugStateSaver saver(out);

  out.nospace().noquote() << static_cast<const Record&>(record)
  << " Localizer["
  << "runway " << record.getRunwayName()
  << ", heading " << record.heading
  << ", width " << record.width
  << "]";
  return out;
}

} // namespace bgl
} // namespace fs
} // namespace atools