#ifndef SERVERSESSIONCONSTANTINTEGER_H
#define SERVERSESSIONCONSTANTINTEGER_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/approach/ServerSessionConstant.h"
#include "src/engines/io/network/utils/FuncTree.h"

class ServerSessionConstantInteger : public ServerSessionConstant
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ServerSessionConstantInteger(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ServerSessionConstantInteger(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ServerSessionConstantInteger(FuncTree tree);
  ServerSessionConstantInteger();
  bool operator==(const ServerSessionConstantInteger &compared);

  int value;

private:
  void _valueFunc(Reader *input);
};

#endif // SERVERSESSIONCONSTANTINTEGER_H