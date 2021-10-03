#ifndef PARTYMEMBERGEOPOSITION_H
#define PARTYMEMBERGEOPOSITION_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class PartyMemberGeoPosition : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PartyMemberGeoPosition(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PartyMemberGeoPosition(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PartyMemberGeoPosition(FuncTree tree);
  PartyMemberGeoPosition();
  bool operator==(const PartyMemberGeoPosition &compared);

  uint memberId;
  int worldX;
  int worldY;
  double mapId;
  uint subAreaId;

private:
  void _memberIdFunc(Reader *input);
  void _worldXFunc(Reader *input);
  void _worldYFunc(Reader *input);
  void _mapIdFunc(Reader *input);
  void _subAreaIdFunc(Reader *input);
};

#endif // PARTYMEMBERGEOPOSITION_H