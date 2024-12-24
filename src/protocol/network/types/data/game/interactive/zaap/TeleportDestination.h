#ifndef TELEPORTDESTINATION_H
#define TELEPORTDESTINATION_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/utils/io/type/FuncTree.h"

class TeleportDestination : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TeleportDestination(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TeleportDestination(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TeleportDestination(FuncTree tree);
  TeleportDestination();
  bool operator==(const TeleportDestination &compared);

  uint type;
  double mapId;
  uint subAreaId;
  uint level;
  uint cost;

private:
  void _typeFunc(Reader *input);
  void _mapIdFunc(Reader *input);
  void _subAreaIdFunc(Reader *input);
  void _levelFunc(Reader *input);
  void _costFunc(Reader *input);
};

#endif // TELEPORTDESTINATION_H