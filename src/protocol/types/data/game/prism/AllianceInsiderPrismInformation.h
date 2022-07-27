#ifndef ALLIANCEINSIDERPRISMINFORMATION_H
#define ALLIANCEINSIDERPRISMINFORMATION_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/data/items/ObjectItem.h"
#include "src/protocol/types/data/game/prism/PrismInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"

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

  uint lastTimeSlotModificationDate;
  uint lastTimeSlotModificationAuthorGuildId;
  double lastTimeSlotModificationAuthorId;
  QString lastTimeSlotModificationAuthorName;
  QList<QSharedPointer<ObjectItem>> modulesObjects;

private:
  void _lastTimeSlotModificationDateFunc(Reader *input);
  void _lastTimeSlotModificationAuthorGuildIdFunc(Reader *input);
  void _lastTimeSlotModificationAuthorIdFunc(Reader *input);
  void _lastTimeSlotModificationAuthorNameFunc(Reader *input);
  void _modulesObjectstreeFunc(Reader *input);
  void _modulesObjectsFunc(Reader *input);

  FuncTree _modulesObjectstree;
};

#endif // ALLIANCEINSIDERPRISMINFORMATION_H