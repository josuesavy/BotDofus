#ifndef SERVERSESSIONCONSTANTINTEGER_H
#define SERVERSESSIONCONSTANTINTEGER_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/approach/ServerSessionConstant.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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