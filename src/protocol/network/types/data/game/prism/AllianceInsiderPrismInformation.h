#ifndef ALLIANCEINSIDERPRISMINFORMATION_H
#define ALLIANCEINSIDERPRISMINFORMATION_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/data/items/ObjectItem.h"
#include "src/protocol/network/types/data/game/prism/PrismInformation.h"
#include "src/utils/io/type/FuncTree.h"

class AllianceInsiderPrismInformation : public PrismInformation
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceInsiderPrismInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceInsiderPrismInformation(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceInsiderPrismInformation(FuncTree tree);
  AllianceInsiderPrismInformation();
  bool operator==(const AllianceInsiderPrismInformation &compared);

  QSharedPointer<ObjectItem> moduleObject;
  int moduleType;
  QSharedPointer<ObjectItem> cristalObject;
  int cristalType;
  uint cristalNumberLeft;

private:
  void _moduleObjecttreeFunc(Reader *input);
  void _moduleTypeFunc(Reader *input);
  void _cristalObjecttreeFunc(Reader *input);
  void _cristalTypeFunc(Reader *input);
  void _cristalNumberLeftFunc(Reader *input);

  FuncTree _moduleObjecttree;
  FuncTree _cristalObjecttree;
};

#endif // ALLIANCEINSIDERPRISMINFORMATION_H