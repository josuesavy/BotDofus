#ifndef ATLASPOINTSINFORMATIONS_H
#define ATLASPOINTSINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/MapCoordinatesExtended.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class AtlasPointsInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AtlasPointsInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AtlasPointsInformations(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AtlasPointsInformations(FuncTree tree);
  AtlasPointsInformations();
  bool operator==(const AtlasPointsInformations &compared);

  uint type;
  QList<QSharedPointer<MapCoordinatesExtended>> coords;

private:
  void _typeFunc(Reader *input);
  void _coordstreeFunc(Reader *input);
  void _coordsFunc(Reader *input);

  FuncTree _coordstree;
};

#endif // ATLASPOINTSINFORMATIONS_H