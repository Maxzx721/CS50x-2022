-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Query the crime scene repots for the crime description
SELECT description
  FROM crime_scene_reports
 WHERE year = 2021
   AND month = 7
   AND day = 28
   AND street = 'Humphrey Street';

-- Gather all transcript from the witnesses, and only id 161 / 162 / 163 are useful
SELECT *
  FROM interviews
 WHERE year = 2021
   AND month = 7
   AND day = 28;

-- Search a list of people's name with the car's license plate
SELECT name
  FROM people
 WHERE license_plate IN
       (SELECT license_plate
          FROM bakery_security_logs
         WHERE year = 2021
           AND month = 7
           AND day = 28
           AND hour = 10
           AND minute >=15
           AND minute <=25);

-- Search for the account number that made transaction on that day
SELECT account_number
  FROM atm_transactions
 WHERE year = 2021
   AND month = 7
   AND day = 28
   AND atm_location = 'Leggett Street'
   AND transaction_type = 'withdraw';

-- Search the name of people who withdraw on that day
SELECT name
  FROM people
  JOIN bank_accounts
 WHERE people.id = bank_accounts.person_id
   AND account_number IN
       (SELECT account_number
          FROM atm_transactions
         WHERE year = 2021
           AND month = 7
           AND day = 28
           AND atm_location = 'Leggett Street'
           AND transaction_type = 'withdraw');

-- Search for the caller and reciever of the phone call
SELECT caller, receiver
  FROM phone_calls
 WHERE year = 2021
   AND month = 7
   AND day = 28
   AND duration < 60;

-- Search for the flight info. for the earliest flight out of Fiftyville on 29/7/2021
SELECT *
  FROM flights
 WHERE year = 2021
   AND month = 7
   AND day = 29
   AND origin_airport_id =
       (SELECT id
          FROM airports
         WHERE city = 'Fiftyville')
 ORDER BY hour, minute
 LIMIT 1;


-- Search for the info. of the flight
SELECT *
  FROM passengers
 WHERE flight_id =
       (SELECT id
          FROM flights
         WHERE year = 2021
           AND month = 7
           AND day = 29
           AND origin_airport_id =
              (SELECT id
                 FROM airports
                WHERE city = 'Fiftyville')
      ORDER BY hour, minute
         LIMIT 1);

-- Locked in the thief
SELECT name
  FROM people
 WHERE license_plate IN
       (SELECT license_plate
          FROM bakery_security_logs
         WHERE year = 2021
           AND month = 7
           AND day = 28
           AND hour = 10
           AND minute >=15
           AND minute <=25)
INTERSECT
SELECT name
  FROM people
  JOIN bank_accounts
 WHERE people.id = bank_accounts.person_id
   AND account_number IN
       (SELECT account_number
          FROM atm_transactions
         WHERE year = 2021
           AND month = 7
           AND day = 28
           AND atm_location = 'Leggett Street'
           AND transaction_type = 'withdraw')
INTERSECT
SELECT name
  FROM people
 WHERE phone_number IN
       (SELECT caller
          FROM phone_calls
         WHERE year = 2021
           AND month = 7
           AND day = 28
           AND duration < 60)
INTERSECT
SELECT name
  FROM people
 WHERE passport_number IN
      (SELECT passport_number
         FROM passengers
         WHERE flight_id =
               (SELECT id
                  FROM flights
                 WHERE year = 2021
                   AND month = 7
                   AND day = 29
                  AND origin_airport_id =
                      (SELECT id
                         FROM airports
                        WHERE city = 'Fiftyville')
      ORDER BY hour, minute
         LIMIT 1));

-- Locked in the accomplice
SELECT name
  FROM people
 WHERE phone_number =
       (SELECT receiver
          FROM phone_calls
         WHERE year = 2021
           AND month = 7
           AND day = 28
           AND duration < 60
           AND caller =
               (SELECT phone_number
                  FROM people
                 WHERE name = 'Bruce'));