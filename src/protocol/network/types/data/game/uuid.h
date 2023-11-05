#ifndef UUID_H
#define UUID_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class uuid : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_uuid(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_uuid(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_uuid(FuncTree tree);
  uuid();
  bool operator==(const uuid &compared);

  QString uuidString;

private:
  void _uuidStringFunc(Reader *input);
};

#endif // UUID_H