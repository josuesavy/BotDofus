#ifndef PRISMGEOLOCALIZEDINFORMATION_H
#define PRISMGEOLOCALIZEDINFORMATION_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/ClassManager.h"
#include "src/engines/io/network/utils/FuncTree.h"

class PrismGeolocalizedInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PrismGeolocalizedInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PrismGeolocalizedInformation(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PrismGeolocalizedInformation(FuncTree tree);
  PrismGeolocalizedInformation();
  bool operator==(const PrismGeolocalizedInformation &compared);

  uint subAreaId;
  uint allianceId;
  int worldX;
  int worldY;
  double mapId;
   prism;

private:
  void _subAreaIdFunc(Reader *input);
  void _allianceIdFunc(Reader *input);
  void _worldXFunc(Reader *input);
  void _worldYFunc(Reader *input);
  void _mapIdFunc(Reader *input);
  void _prismtreeFunc(Reader *input);

  FuncTree _prismtree;
};

#endif // PRISMGEOLOCALIZEDINFORMATION_H