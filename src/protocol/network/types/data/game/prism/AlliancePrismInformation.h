#ifndef ALLIANCEPRISMINFORMATION_H
#define ALLIANCEPRISMINFORMATION_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/context/roleplay/AllianceInformation.h"
#include "src/protocol/network/types/data/game/prism/PrismInformation.h"
#include "src/utils/io/type/FuncTree.h"

class AlliancePrismInformation : public PrismInformation
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AlliancePrismInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AlliancePrismInformation(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AlliancePrismInformation(FuncTree tree);
  AlliancePrismInformation();
  bool operator==(const AlliancePrismInformation &compared);

  QSharedPointer<AllianceInformation> alliance;

private:
  void _alliancetreeFunc(Reader *input);

  FuncTree _alliancetree;
};

#endif // ALLIANCEPRISMINFORMATION_H