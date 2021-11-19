#ifndef PADDOCKCONTENTINFORMATIONS_H
#define PADDOCKCONTENTINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/paddock/MountInformationsForPaddock.h"
#include "src/protocol/types/data/game/paddock/PaddockInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"

class PaddockContentInformations : public PaddockInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PaddockContentInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PaddockContentInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PaddockContentInformations(FuncTree tree);
  PaddockContentInformations();
  bool operator==(const PaddockContentInformations &compared);

  double paddockId;
  int worldX;
  int worldY;
  double mapId;
  uint subAreaId;
  bool abandonned;
  QList<MountInformationsForPaddock> mountsInformations;

private:
  void _paddockIdFunc(Reader *input);
  void _worldXFunc(Reader *input);
  void _worldYFunc(Reader *input);
  void _mapIdFunc(Reader *input);
  void _subAreaIdFunc(Reader *input);
  void _abandonnedFunc(Reader *input);
  void _mountsInformationstreeFunc(Reader *input);
  void _mountsInformationsFunc(Reader *input);

  FuncTree _mountsInformationstree;
};

#endif // PADDOCKCONTENTINFORMATIONS_H