#ifndef PROTECTEDENTITYWAITINGFORHELPINFO_H
#define PROTECTEDENTITYWAITINGFORHELPINFO_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/utils/io/type/FuncTree.h"

class ProtectedEntityWaitingForHelpInfo : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ProtectedEntityWaitingForHelpInfo(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ProtectedEntityWaitingForHelpInfo(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ProtectedEntityWaitingForHelpInfo(FuncTree tree);
  ProtectedEntityWaitingForHelpInfo();
  bool operator==(const ProtectedEntityWaitingForHelpInfo &compared);

  int timeLeftBeforeFight;
  int waitTimeForPlacement;
  uint nbPositionForDefensors;

private:
  void _timeLeftBeforeFightFunc(Reader *input);
  void _waitTimeForPlacementFunc(Reader *input);
  void _nbPositionForDefensorsFunc(Reader *input);
};

#endif // PROTECTEDENTITYWAITINGFORHELPINFO_H