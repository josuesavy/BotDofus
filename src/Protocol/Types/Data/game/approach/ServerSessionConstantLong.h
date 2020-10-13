#ifndef SERVERSESSIONCONSTANTLONG_H
#define SERVERSESSIONCONSTANTLONG_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/approach/ServerSessionConstant.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class ServerSessionConstantLong : public ServerSessionConstant
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ServerSessionConstantLong(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ServerSessionConstantLong(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ServerSessionConstantLong(FuncTree tree);
  ServerSessionConstantLong();
  bool operator==(const ServerSessionConstantLong &compared);

  double value;

private:
  void _valueFunc(Reader *input);
};

#endif // SERVERSESSIONCONSTANTLONG_H