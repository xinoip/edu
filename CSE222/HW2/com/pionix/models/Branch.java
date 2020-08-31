package com.pionix.models;

/**
 * Branch class represents a real life branch for a cargo company
 *
 */
public class Branch {
    /**
     * Branch name
     */
    private final String name;

    /**
     * Constructor for creating a branch with name
     *
     * @param name branch name
     */
    public Branch(String name) {
        this.name = name;
    }

    /**
     * Gets the branch name
     *
     * @return branch name
     */
    public String getName() {
        return name;
    }

    @Override
    public String toString() {
        return "Branch name: " + name;
    }
}
