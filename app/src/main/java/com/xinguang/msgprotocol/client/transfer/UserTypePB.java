// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: UserType.proto

package com.xinguang.msgprotocol.client.transfer;

public final class UserTypePB {
  private UserTypePB() {}
  public static void registerAllExtensions(
      com.google.protobuf.ExtensionRegistryLite registry) {
  }

  public static void registerAllExtensions(
      com.google.protobuf.ExtensionRegistry registry) {
    registerAllExtensions(
        (com.google.protobuf.ExtensionRegistryLite) registry);
  }
  /**
   * Protobuf enum {@code UserType}
   */
  public enum UserType
      implements com.google.protobuf.ProtocolMessageEnum {
    /**
     * <pre>
     *骑士
     * </pre>
     *
     * <code>RIDER = 0;</code>
     */
    RIDER(0),
    /**
     * <pre>
     *商家
     * </pre>
     *
     * <code>MERCHANT = 1;</code>
     */
    MERCHANT(1),
    /**
     * <pre>
     *司机
     * </pre>
     *
     * <code>DRIVER = 2;</code>
     */
    DRIVER(2),
    UNRECOGNIZED(-1),
    ;

    /**
     * <pre>
     *骑士
     * </pre>
     *
     * <code>RIDER = 0;</code>
     */
    public static final int RIDER_VALUE = 0;
    /**
     * <pre>
     *商家
     * </pre>
     *
     * <code>MERCHANT = 1;</code>
     */
    public static final int MERCHANT_VALUE = 1;
    /**
     * <pre>
     *司机
     * </pre>
     *
     * <code>DRIVER = 2;</code>
     */
    public static final int DRIVER_VALUE = 2;


    public final int getNumber() {
      if (this == UNRECOGNIZED) {
        throw new java.lang.IllegalArgumentException(
            "Can't get the number of an unknown enum value.");
      }
      return value;
    }

    /**
     * @deprecated Use {@link #forNumber(int)} instead.
     */
    @java.lang.Deprecated
    public static UserType valueOf(int value) {
      return forNumber(value);
    }

    public static UserType forNumber(int value) {
      switch (value) {
        case 0: return RIDER;
        case 1: return MERCHANT;
        case 2: return DRIVER;
        default: return null;
      }
    }

    public static com.google.protobuf.Internal.EnumLiteMap<UserType>
        internalGetValueMap() {
      return internalValueMap;
    }
    private static final com.google.protobuf.Internal.EnumLiteMap<
        UserType> internalValueMap =
          new com.google.protobuf.Internal.EnumLiteMap<UserType>() {
            public UserType findValueByNumber(int number) {
              return UserType.forNumber(number);
            }
          };

    public final com.google.protobuf.Descriptors.EnumValueDescriptor
        getValueDescriptor() {
      return getDescriptor().getValues().get(ordinal());
    }
    public final com.google.protobuf.Descriptors.EnumDescriptor
        getDescriptorForType() {
      return getDescriptor();
    }
    public static final com.google.protobuf.Descriptors.EnumDescriptor
        getDescriptor() {
      return com.xinguang.msgprotocol.client.transfer.UserTypePB.getDescriptor().getEnumTypes().get(0);
    }

    private static final UserType[] VALUES = values();

    public static UserType valueOf(
        com.google.protobuf.Descriptors.EnumValueDescriptor desc) {
      if (desc.getType() != getDescriptor()) {
        throw new java.lang.IllegalArgumentException(
          "EnumValueDescriptor is not for this type.");
      }
      if (desc.getIndex() == -1) {
        return UNRECOGNIZED;
      }
      return VALUES[desc.getIndex()];
    }

    private final int value;

    private UserType(int value) {
      this.value = value;
    }

    // @@protoc_insertion_point(enum_scope:UserType)
  }


  public static com.google.protobuf.Descriptors.FileDescriptor
      getDescriptor() {
    return descriptor;
  }
  private static  com.google.protobuf.Descriptors.FileDescriptor
      descriptor;
  static {
    java.lang.String[] descriptorData = {
      "\n\016UserType.proto*/\n\010UserType\022\t\n\005RIDER\020\000\022" +
      "\014\n\010MERCHANT\020\001\022\n\n\006DRIVER\020\002B6\n(com.xinguan" +
      "g.msgprotocol.client.transferB\nUserTypeP" +
      "Bb\006proto3"
    };
    com.google.protobuf.Descriptors.FileDescriptor.InternalDescriptorAssigner assigner =
        new com.google.protobuf.Descriptors.FileDescriptor.    InternalDescriptorAssigner() {
          public com.google.protobuf.ExtensionRegistry assignDescriptors(
              com.google.protobuf.Descriptors.FileDescriptor root) {
            descriptor = root;
            return null;
          }
        };
    com.google.protobuf.Descriptors.FileDescriptor
      .internalBuildGeneratedFileFrom(descriptorData,
        new com.google.protobuf.Descriptors.FileDescriptor[] {
        }, assigner);
  }

  // @@protoc_insertion_point(outer_class_scope)
}
