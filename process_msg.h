/**
 * @file     process_msg.h
 * @Author   Andrey Dmitriev (dmandry92@gmail.com)
 * @date     September, 2015
 * @brief    Message processing library 
 */

#ifndef __IFMO_DISTRIBUTED_CLASS_PROCESS_MSG__H
#define __IFMO_DISTRIBUTED_CLASS_PROCESS_MSG__H

#include <stdint.h>

#include "ipc.h"
#include "banking.h"

//------------------------------------------------------------------------------

/** Processes a message given.
 *
 * @param msg            Message
 * @param dst            Id of the dst process
 * @param src            Id of the src process
 * 
 */
void process_msg(Message *msg, local_id dst, local_id src);

//------------------------------------------------------------------------------

/** Creates a typed message with a given payload.
 *
 * @param type            Type of a message
 * @param payload_len     Length of payload
 * @param payload         Message payload
 *
 * @return message pointer on success, EXIT_FAILURE on error
 */
Message *create_msg(int16_t type, char *payload, BalanceHistory *history);

/** Creates a payload with a given type.
 *
 * @param type            Type of a message
 * @param id              Id of the process
 * @param order           Payload for TRANSFER type
 * @param history         Payload for BALANCE_HISTORY type
 *
 * @return payload pointer on success, EXIT_FAILURE on error
 */
char *create_payload(int16_t type,
                     local_id id,
                     TransferOrder *order,
                     BalanceHistory *history);

/** Counts types of messages sent by this process.
 *
 * @param id              Id of the process
 * @param type            Type of a message
 *
 */
void count_sent_num(local_id id, int16_t type);

/** Returns a number of messages recieved with a given type.
 *
 * @param type            Type of a message
 *
 * @return number pointer on success, EXIT_FAILURE on error
 */
int8_t *get_rcvd_num(int16_t type);

/** Returns an array of numbers of messages recieved by process with a given type.
 *
 * @param type            Type of a message
 *
 * @return array on success, EXIT_FAILURE on error
 */
int *get_rcvd(int16_t type);

//------------------------------------------------------------------------------

#endif // __IFMO_DISTRIBUTED_CLASS_PROCESS_MSG__H
