#ifndef GAMESERVERINFORMATIONS_H
#define GAMESERVERINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/BooleanByteWrapper.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GameServerInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameServerInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameServerInformations(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameServerInformations(FuncTree tree);
  GameServerInformations();
  bool operator==(const GameServerInformations &compared);

  uint id;
  int type;
  bool isMonoAccount;
  uint status;
  uint completion;
  bool isSelectable;
  uint charactersCount;
  uint charactersSlots;
  double date;

private:
  void deserializeByteBoxes(Reader *input);
  void _idFunc(Reader *input);
  void _typeFunc(Reader *input);
  void _statusFunc(Reader *input);
  void _completionFunc(Reader *input);
  void _charactersCountFunc(Reader *input);
  void _charactersSlotsFunc(Reader *input);
  void _dateFunc(Reader *input);
};

#endif // GAMESERVERINFORMATIONS_H