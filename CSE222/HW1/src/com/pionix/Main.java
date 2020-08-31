package com.pionix;

/**
 * AutoCargo program implements an application that
 * simulates a cargo system.
 *
 * Application's memory is run-time only.
 *
 * Application is trying to mimic a real world database.
 *
 * @author Bugra Eren Yilmaz
 * @version 1.0
 * @since 2020-02-24
 */
public class Main {

    public static void main(String[] args) {
        Database.seedDatabase();

        UserInterface.loginMenu();
    }
}
